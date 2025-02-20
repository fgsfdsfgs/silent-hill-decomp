#ifndef _FSQUEUE_H
#define _FSQUEUE_H

#include "common.h"
#include "main/fileinfo.h"

#define FS_QUEUE_LEN 32 /** FS queue size. */

#define FS_BUFFER0 ((void*)0x8010A600)
#define FS_BUFFER1 ((void*)0x801E2600)

/**
 * @brief Extra queue entry data describing where to upload a TIM after reading.
 * See `FsQueueExtra`.
 * @note `tPage` seems to be byte swapped.
 */
typedef struct
{
    u16 tPage;
    u8  u;
    u8  v;
    s16 clutX;
    s16 clutY;
} FsImageDesc;

/**
 * @brief Extra queue entry data describing something related to loading some ANM files.
 * See `FsQueueExtra`.
 */
typedef struct
{
    u32 field00;
    u32 field04;
    u32 field08;
} FsAnmDesc;

/**
 * @brief Extra data passed with the queue entry.
 *
 * Seems to be either a TIM descriptor (`image`), or something for ANM files (`anm`).
 *
 * For `image` usage, see `Fs_QueuePostLoadTim_80011B24`.
 *
 * Unknown what exactly `anm` is, but it is used with preprocess type 2, which is only used
 * for some ANM files, but not others. See `Fs_QueuePostLoadAnm_80011C3C`.
 */
typedef union
{
    FsImageDesc image; /** Location in VRAM where to upload a TIM during postload. */
    FsAnmDesc   anm;   /** Unknown. Used when loading some ANM files. */
} FsQueueExtra;

/**
 * @brief FS queue entry.
 *
 * Entry in the FS queue.
 * Holds the state of one read/seek operation and a pointer to the `FileInfo` of the file it's for.
 */
typedef struct
{
    const FileInfo* info;         /** Pointer to the file table entry of the file this entry is for. */
    u8              operation;    /** What to do. See `FsQueueOperation`. */
    u8              postLoad;     /** What to do after `operation` is done. See `FsQueuePostLoadType`. */
    u8              allocate;     /** If 1, allocate a buffer for `data` from `g_FsMemory`, otherwise use `externalData` */
    u8              unused0;      /** Unused or padding. */
    void*           externalData; /** Pointer to an external buffer. */
    u32             unused1;      /** Unused but set by `Fs_QueueEnqueue_80011074`. */
    FsQueueExtra    extra;        /** Extra data, used during post load. */
    void*           data;         /** Output buffer. Either allocated or same as `externalData`. */
} FsQueueEntry;

/** Queue pointer.
 * These had to be wrapped into a struct for some code to match.
 * Used for last added element, current read/seek op and current post process op.
 */
typedef struct
{
    s32           idx; /** Index in `entries` this is pointing to. */
    FsQueueEntry* ptr; /** Entry in `entries` this is pointing to. */
} FsQueuePtr;

/**
 * @brief FS queue.
 *
 * State of the file system operations queue.
 *
 * The queue is used for async reads from the CD and from PCDRV and async seeking on the CD.
 * Each operation can optionally include a post-process (post-load) step that happens after the main operation is complete.
 * For example, parsing a TIM file after reading it.
 *
 * New entries are added by `Fs_QueueEnqueue_80011074`. The queue is processed in `Fs_UpdateQueue_80011260`.
 *
 * @note Assuming this is a single struct because there's a `bzero` that zeroes out this entire block.
 */
typedef struct
{
    FsQueueEntry entries[FS_QUEUE_LEN]; /** Circular buffer for the queue itself. */
    FsQueuePtr   last;                  /** Index and address of the last added entry. */
    FsQueuePtr   read;                  /** Index and address the current operation entry to process. */
    FsQueuePtr   postLoad;              /** Index and address of the current operation entry to postprocess. */
    u32          state;                 /** Current processing stage. `FsQueueReadState` for reads, `FsQueueSeekState` for seeks. */
    u32          postLoadState;         /** Current postprocessing stage. See `FsQueuePostLoadState`. */
    s32          resetTimer0;           /** Reset timer (lo). Incs up to 8, then incs `reset_timer_1`. See `Fs_ResetQueueTick_80011884`. */
    s32          resetTimer1;           /** Reset timer (hi). When it reaches 9, `CdReset` is called. See `Fs_ResetQueueTick_80011884`. */
} FsQueue;

/** @brief `FsQueue::state` values when processing a read operation (`Fs_UpdateQueueRead_800114C4`).
 *
 * When `Fs_UpdateQueue_80011260` is called and the current op is a read, it will perform the corresponding action below.
 * Unless otherwise specified, success of that action will advance to the next state.
 *
 * `FSQS_READ_RESET` and `FSQS_READ_CHECK` perform one check/tick iteration every time `Fs_UpdateQueue_80011260` is called
 * and only advance to the next state when they're done.
 */
enum FsQueueReadState
{
    FSQS_READ_ALLOCATE = 0, /** Allocate memory for the current read operation (`fsQueueAllocData`), if needed. */
    FSQS_READ_CHECK    = 1, /** Check if the current read operation can proceed (`Fs_CanQueueRead_800116BC`). Goto next state if it can. */
    FSQS_READ_SETLOC   = 2, /** Set start sector from `info` (`Fs_TickQueueSetLoc_800117E8`). If failure, goto `FSQS_READ_RESET`. */
    FSQS_READ_READ     = 3, /** Read from CD (`Fs_TickQueueRead_8001182C`). If failure, goto `FSQS_READ_RESET`. */
    FSQS_READ_SYNC     = 4, /** Wait for read to complete. If failure, goto `FSQS_READ_RESET`. */
    FSQS_READ_RESET    = 5  /** Tick the reset timers (`Fs_ResetQueueTick_80011884`). When done, reset CD driver and goto `FSQS_READ_SETLOC`. */
};

/** @brief `FsQueue::state` values when processing a seek operation (`Fs_UpdateQueueSeek_8001137C`).
 *
 * When `Fs_UpdateQueue_80011260` is called and the current op is a seek, it will perform the corresponding action below.
 * Unless otherwise specified, success of that action will advance to the next state.
 */
enum FsQueueSeekState
{
    FSQS_SEEK_SET_LOC = 0, /** Set seek sector from `info` (`Fs_TickQueueSetLoc_800117E8`). */
    FSQS_SEEK_SEEKL   = 1, /** Start seeking to above location (via `CdControl(CdlSeekL, ...)`). */
    FSQS_SEEK_SYNC    = 2, /** Wait for seek to complete (`CdSync()`). If `CdlDiskError`, goto `FSQS_SEEK_RESET`. */
    FSQS_SEEK_RESET   = 3  /** See `FSQS_READ_RESET`. When done, reset CD driver and go to `FSQS_SEEK_SET_LOC`. */
};

/** @brief Post load state.
 *
 * When `Fs_UpdateQueue_80011260` is called it will perform an action on the current post load entry, if any,
 * according to `g_FsQueue.postload_state`, which can have one of these values.
 *
 * See `FsQueue::postload_state`.
 */
enum FsQueuePostLoadState
{
    FSQS_POST_LOAD_INIT = 0, /** Check for allocated memory and proceed to `SKIP` or `EXEC`. */
    FSQS_POST_LOAD_SKIP = 1, /** Skip post loading because this entry owns allocated memory. */
    FSQS_POST_LOAD_EXEC = 2  /** Execute post load operation. */
};

/** @brief Post load types.
 *
 * What to do with a queue entry after its `operation` is done. Might be better described as "file format", but
 * it only applies to two filetypes.
 *
 * See `FsQueueEntry::postload`.
 */
enum FsQueuePostLoadType
{
    FS_POST_LOAD_NONE = 0, /** Do nothing. */
    FS_POST_LOAD_TIM  = 1, /** Parse TIM file (`Fs_QueuePostLoadTim_80011B24`). Can use `extra.image`. */
    FS_POST_LOAD_ANM  = 2  /** Parse ANM file maybe (`Fs_QueuePostLoadAnm_80011C3C`). Always uses `extra.anm`. */
};

/** @brief FS queue operation type.
 * What to do for a queue entry.
 * See `FsQueueEntry::operation`.
 */
enum FsQueueOperation
{
    FS_OP_NONE = 0, /** Uninitialized. */
    FS_OP_SEEK = 1, /** Seek to file location on CD (`Fs_UpdateQueueSeek_8001137C`). */
    FS_OP_READ = 2  /** Read from CD (`Fs_UpdateQueueRead_800114C4`). */
};

/** The FS queue. See `FsQueue`. */
extern FsQueue g_FsQueue;

/** @brief Initialize FS queue and FS memory.
 * Initializes `g_FsQueue` and calls `Fs_InitializeMem_80011C70`.
 */
void Fs_InitializeQueue_80011170(void);

/** Check if queue entry index `arg0` has been loaded and post loaded.
 * 
 * @param arg0 The index of the queue entry to check.
 * @return 1 if the entry has been fully processed, 0 otherwise.
 */
s32 Fs_IsQueueEntryLoaded_80010e58(s32 arg0);

/** Get number of operations currently in queue.
 * @return Number of operations in queue. Includes both pending reads and pending post loads.
 */
s32 Fs_GetQueueLength_80010E68(void);

/** Unknown. If queue is empty, call `func_8003c850`.
 * @return 1 when queue is empty and the call suceeds, 0 otherwise.
 */
s32 Fs_DoQueueThingWhenEmpty_80010e84(void);

/** If `entry->allocate` is set, allocate memory for `entry->data`, otherwise use `entry->external_data`.
 * 
 * @param entry Entry to allocate memory for.
 * @return 1 if allocation was successful or was not needed, 0 otherwise.
 */
s32 Fs_AllocQueueEntryData_80011630(FsQueueEntry* entry);

/** @brief Add new operation to the queue.
 *
 * If the queue is full, will spin while calling `Fs_UpdateQueue_80011260` and wait until space frees up.
 * Called by all of the `fsQueueStart*` functions.
 *
 * @param fileIdx File table index of the file to load/seek.
 * @param op Operation type (`FsQueueOperation`).
 * @param postLoad Postload type (`FsQueuePostLoadType`).
 * @param alloc Whether to allocate owned memory for this operation (`FsQueueEntry::allocate`).
 * @param unused1 Value for `FsQueueEntry::unused1`. Seems to be unused.
 * @param extra Extra data for operation (`FsQueueEntry::extra`).
 * @return Index of the new queue entry.
 */
s32 Fs_QueueEnqueue_80011074(s32 fileIdx, u8 op, u8 postLoad, u8 alloc, void* data, u32 unused1, FsQueueExtra* extra);

/** Add a new read operation to the queue.
 * 
 * @param fileIdx File table index of the file to read.
 * @param dest Destination buffer. Seems there are no size checks.
 * @return Index of the new queue entry.
 */
s32 Fs_StartQueueRead_80010F68(s32 fileIdx, void* dest);

/** @brief Add a new TIM read operation to the queue.
 * Adds a read operation with `postload = FS_POSTLOAD_TIM`.
 * 
 * @param fileIdx File table index of the file to read.
 * @param dest Destination buffer. Seems there are no size checks.
 * @param image Where to upload the TIM in VRAM.
 * @return Index of the new queue entry.
 */
s32 Fs_StartQueueReadTim_80010F9C(s32 fileIdx, void* dest, FsImageDesc* image);

/** @brief Add a new ANM read operation to the queue.
 * Adds a read operation with `postload = FS_POSTLOAD_ANM`.
 * 
 * @note Does not actually take a file number, but instead takes one from an array of structs at 0x800a90fc in bodyprog,
 * using `arg1` as an index. Does not seem to take a `FsAnmDesc` pointer either. Maybe by value?
 * 
 * @param arg0
 * @param arg1 Index of something in an array in bodyprog.
 * @param arg2 Destination buffer?
 * @param arg3
 * @return Index of the new queue entry.
 */
s32 Fs_StartQueueReadAnm_80011018(s32 arg0, s32 arg1, void* arg2, s32 arg3);

/** Add a new seek operation to the queue.
 * @param fileIdx File table index of the file to seek to.
 * @return Index of the new queue entry.
 */
s32 Fs_StartQueueSeek_80010f34(s32 fileIdx);

/** Process a read from PCDRV. Seems to be unused in release.
 * @param entry PCDRV read operation entry to process.
 * @return 1 if succeeded, 0 otherwise.
 */
s32 Fs_TickQueueReadPcDvr_8001190c(FsQueueEntry* entry);

/** @brief Process `FSQS_READ_SETLOC` or `FSQS_SEEK_SETLOC` state: set target sector.
 *
 * Calls `CdControl(CdlSetloc, ...)`.
 *
 * @param entry Entry to process.
 * @return 1 if succeded, 0 if `CdControl` failed.
 */
s32 Fs_TickQueueSetLoc_800117E8(FsQueueEntry* entry);

/** @brief Process `FSQS_READ_READ` state: read from CD.
 *
 * Calls `CdRead()`.
 *
 * @param entry Entry to process.
 * @return 1 if succeded, 0 if `CdControl` failed.
 */
s32 Fs_TickQueueRead_8001182C(FsQueueEntry* entry);

/** @brief Process `FSQS_READ_RESET` or `FSQS_SEEK_RESET` state: wait for a bit and reset CD driver.
 *
 * Increments `g_FsQueue.reset_timer_0` once. If it has reached 8, clears it and increments `g_FsQueue.reset_timer_1`.
 * If `g_FsQueue.reset_timer_1` has reached 9, clears it and calls `CdReset()`.
 *
 * @param entry Entry to process.
 * @return 1 if succeded, 0 if `CdControl` failed.
 */
s32 Fs_ResetQueueTick_80011884(FsQueueEntry* entry);

/** @brief Ticks the FS queue once.
 *
 * Depending on current read entry's operation type, either ticks reading it (`Fs_UpdateQueueRead_800114C4`) or seeking it (`Fs_UpdateQueueSeek_8001137C`).
 * If they return 1, advances `g_FsQueue.read.idx` and `g_FsQueue.read.ptr`.
 *
 * Regardless of the outcome of the above, also ticks postloading (`Fs_UpdateQueuePostLoad_80011A4C`) if there is an entry to postload.
 * If that reports that the current postload entry is done postloading, advances `g_FsQueue.postLoad.idx` and `g_FsQueue.postLoadLtr`.
 */
void Fs_UpdateQueue_80011260(void);

/** @brief Ticks a read operation once.
 *
 * Performs one step in the reading process according to `g_FsQueue.state`. When the whole process is done, returns 1.
 *
 * @param entry Entry to tick.
 * @return 1 when `entry` is done loading, 0 otherwise.
 */
s32 Fs_UpdateQueueRead_800114C4(FsQueueEntry* entry);

/** @brief Ticks a seek operation once.
 *
 * Performs one step in the seeking process according to `g_FsQueue.state`. When the whole process is done, returns 1.
 *
 * @param entry Entry to tick.
 * @return 1 when `entry` is done seeking, 0 otherwise.
 */
s32 Fs_UpdateQueueSeek_8001137C(FsQueueEntry* entry);

/** @brief Ticks postloading once.
 *
 * Performs one step in the postloading process according to `entry->postload_state`. When the whole process is done, returns 1.
 *
 * @param entry Entry to tick.
 * @return 1 when `entry` is done postloading, 0 otherwise.
 */
s32 Fs_UpdateQueuePostLoad_80011A4C(FsQueueEntry* entry);

/** @brief Parse a TIM file after loading it.
 *
 * Called during postloading for TIM files (`entry->postload = 1`).
 * Will use `OpenTIM`/`ReadTIM` to parse the loaded data and then upload it via `LoadImage`.
 * If `entry->extra.image.u` is not 0xFF, will override the XY components of the pixel and CLUT rects with values from `image`.
 *
 * @param entry Entry to parse.
 * @return Always 1.
 */
s32 Fs_QueuePostLoadTim_80011B24(FsQueueEntry* entry);

/** @brief Parse an ANM file after loading it?
 *
 * Called during postloading for some ANM files (when `entry->postload = 2`).
 * For example, it is called for CLD2.ANM, SRL.ANM, SBL.ANM (maybe ones used for NPCs?), but not for others
 * (e.g. HB_M0S01.ANM).
 *
 * Calls into BODYPROG, where a function gets a `GsCOORDINATE2` from somewhere in the loaded data.
 * Always uses data from `entry->extra.anm`.
 *
 * @param entry Entry to parse.
 * @return Always 1.
 */
s32 Fs_QueuePostLoadAnm_80011C3C(FsQueueEntry* entry);

/** @brief Check if specified read operation entry can be processed.
 *
 * Checks if loading `entry` will clobber any memory that was allocated for pending entries in the queue,
 * or memory that's used for postloading.
 *
 * @param entry Entry to check against.
 * @return 1 if the entry can be loaded without clobbering anything, 0 otherwise.
 */
s32 Fs_CanQueueRead_800116BC(FsQueueEntry* entry);

/** Seems to clear the queue. */
void Fs_ResetQueue_800111dc(void);

/** Spin-waits for the queue to become empty while calling `Fs_UpdateQueue_80011260`.
 * Calls some bodyprog functions before and after the wait, `VSync` in the wait and `DrawSync` after the wait.
 */
void Fs_WaitForEmptyQueue_80010ecc(void);

/** @brief Check if two buffers overlap in memory. Used by `Fs_CanQueueRead_800116BC`.
 * 
 * @param data0 Start of the first buffer.
 * @param size0 Size of the first buffer in bytes.
 * @param data1 Start of the second buffer.
 * @param size1 Size of the second buffer in bytes.
 * @return 1 if buffers overlap, 0 otherwise.
 */
s32 Fs_DoQueueBuffersOverlap_800117AC(u8* data0, u32 size0, u8* data1, u32 size1);

#endif
