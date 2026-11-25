#ifndef BRUTE_H
#define BRUTE_H

#include <stdio.h>
#include <stdint.h>

typedef struct
{
    uint16_t p;
    uint16_t q;
} Q_P;

uint32_t FastExponentiation_decrypt(uint64_t C, uint64_t e, uint64_t n);
uint64_t Get_d(uint64_t e_val, Q_P PrimePair);
void bruteForceMethod(FILE *EncryptedFile_ptr, uint64_t n, uint64_t e);

#endif