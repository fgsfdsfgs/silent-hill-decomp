#include "main_2.h"

s32 FUN_80010e58(s32 arg0) { return arg0 < D_800230A8; }

s32 FUN_80010E68(void) { return D_80022C98[0x100] + 1 - D_80022C98[0x104]; }

s32 FUN_80010e84(void) {
  s32 result;

  D_800C489C = 1;

  result = 0;

  if (FUN_80010E68() == 0) {
    result = FUN_8003c850() != 0;
  }

  return result;
}

INCLUDE_ASM("asm/main/nonmatchings/main_2", FUN_80010ecc);

INCLUDE_ASM("asm/main/nonmatchings/main_2", FUN_80010f34);

INCLUDE_ASM("asm/main/nonmatchings/main_2", FUN_80010F68);

INCLUDE_ASM("asm/main/nonmatchings/main_2", FUN_80010F9C);

INCLUDE_ASM("asm/main/nonmatchings/main_2", FUN_80011018);

INCLUDE_ASM("asm/main/nonmatchings/main_2", FUN_80011074);

INCLUDE_ASM("asm/main/nonmatchings/main_2", FUN_80011170);

INCLUDE_ASM("asm/main/nonmatchings/main_2", FUN_800111dc);

INCLUDE_ASM("asm/main/nonmatchings/main_2", FUN_80011260);

INCLUDE_ASM("asm/main/nonmatchings/main_2", FUN_8001137C);