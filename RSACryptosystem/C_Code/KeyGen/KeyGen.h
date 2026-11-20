
#ifndef KEY_GEN_H
#define KEY_GEN_H
#include <stdint.h>
#include "KeyGen.h"
typedef struct
{
    uint16_t p;
    uint16_t q;

} Q_P;
#define Prime 1
#define NOT_Prime 0

#define MAX_Specified 65535
#define MIN_Specified 32768

#define Specified_e_Value 65537
#ifdef Helper_Functions

uint8_t is_Prime(uint64_t n);
uint16_t random_ranged_16_bit(uint16_t low, uint16_t high);
uint16_t random_prime_16Bit(uint16_t low, uint16_t high);
Q_P Get_KeyGen_PrimePairs();
uint64_t Get_d(uint64_t e_val, Q_P PrimePair);
#endif

void KeyGenAlgorithm(const char *PrivateKeyFilePlaceAndName, const char *PublicKeyFilePlaceAndName);

#endif
