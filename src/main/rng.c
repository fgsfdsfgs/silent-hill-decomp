#include "main/rng.h"

/**
 * @brief Global variable storing the current random seed for the `rngRand32`
 * function. The value is updated with each call to the RNG functions.
 */
u32 g_RngSeed = 0;

/**
 * @brief Generates a new random 32-bit unsigned integer and updates the
 * `g_RngSeed`.
 *
 * This function implements a Linear Congruential Generator (LCG) Random Number
 * Generator (RNG) algorithm, as outlined in "Numerical Recipes" (Second
 * Edition, Chapter 7.1, An Even Quicker Generator). It produces a pseudo-random
 * 32-bit unsigned integer value.
 *
 * @return A new pseudo-random 32-bit unsigned integer (u32).
 */
u32 rngRand32(void)
{
    u32 nextSeed = g_RngSeed;

    nextSeed = (nextSeed * 1664525) + 1013904223;
    g_RngSeed = nextSeed;

    return nextSeed;
}

/**
 * @brief Generates a new random positive 16-bit short integer.
 * 
 * This function calls `rngRand32` to generate a random number, then
 * shifts the result right to produce a value within the range
 * of 0 to 0x7FFF (16-bit - sign).
 *
 * @return A random positive 16-bit short integer (0 to 0x7FFF).
 */
s16 rngRand16(void)
{
    return rngRand32() >> 0x11;
}

/**
 * @brief Returns the current random seed value.
 *
 * This function retrieves and returns the current value of the global variable
 * `g_RngSeed`.
 *
 * @return The current random seed as a 32-bit unsigned integer (u32).
 */
u32 rngGetSeed(void)
{
    return g_RngSeed;
}

/**
 * @brief Sets the random seed to a specified value.
 *
 * This function updates the global variable `g_RngSeed` with the given
 * seed value.
 *
 * @param newSeed The new seed value to be set, as a 32-bit unsigned integer
 * (u32).
 */
void rngSetSeed(u32 nextSeed)
{
    g_RngSeed = nextSeed;
}

/**
 * @brief Generates a new random 12-bit short integer.
 *
 * This function calls `rngRand32` to generate a random number, then
 * shifts the result right to produce a value within the range
 * of 0 to 0xFFF (12-bit).
 *
 * @return A random 12-bit short integer (0 to 0xFFF).
 */
u16 rngRand12(void)
{
    return rngRand32() >> 0x14;
}
