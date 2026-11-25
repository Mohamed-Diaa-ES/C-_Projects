#include "Brute.h"
#include <stdlib.h>

uint32_t FastExponentiation_decrypt(uint64_t C, uint64_t e, uint64_t n)
{
    if (n == 1)
        return 0;

    uint64_t result = 1;
    uint64_t M_Mod_N = C % n;

    while (e > 0)
    {
        if (e % 2)
        {
            result = ((__uint128_t)result * M_Mod_N) % n;
        }
        M_Mod_N = ((__uint128_t)M_Mod_N * M_Mod_N) % n;
        e /= 2;
    }
    return (uint32_t)result;
}

uint64_t Get_d(uint64_t e_val, Q_P PrimePair)
{
    uint64_t phi_n = (uint64_t)(PrimePair.p - 1) * (uint64_t)(PrimePair.q - 1);

    for (uint64_t k = 1; k < e_val; k++)
    {
        if ((k * phi_n + 1) % e_val == 0)
        {
            return (k * phi_n + 1) / e_val;
        }
    }
    return 0;
}

void bruteForceMethod(FILE *EncryptedFile_ptr, uint64_t n, uint64_t e)
{
    uint16_t p = 0, q = 0;
    uint64_t d;

    for (uint32_t i = 32769; i <= 65535; i += 2)
    {
        if (n % i == 0)
        {
            p = (uint16_t)i;
            q = (uint16_t)(n / i);
            break;
        }
    }

    if (p == 0 || q == 0)
    {
        fprintf(stderr, "Error: failed to factor n = %llu\n", (unsigned long long)n);
        exit(1);
    }

    Q_P valOfPrimePair = {p, q};
    d = Get_d(e, valOfPrimePair);
    uint32_t C = 0;

    while (fscanf(EncryptedFile_ptr, "%8x", &C) == 1)
    {
        uint32_t M = FastExponentiation_decrypt(C, d, n);
        if (M >= 256)
        {
            fprintf(stderr, "Error: decrypted value %u out of byte range\n corrupted File in the first place\n", M);
            exit(1);
        }
        fputc((uint8_t)M, stdout);
    }
}