#include "mapping_values.h"

uint32_t FastExponentiation(uint8_t m, uint64_t e, uint64_t n)
{
    if (n == 1)
        return 0;

    uint64_t result = 1;
    uint64_t M_Mod_N = m % n;

    while (e > 0)
    {
        if (e % 2)
        {
            result = (result * M_Mod_N) % n;
        }
        M_Mod_N = (M_Mod_N * M_Mod_N) % n;
        e /= 2;
    }
    return (uint32_t)result;
}

void mapValuesMethod(FILE *EncryptedFile_ptr, uint64_t n, uint64_t e)
{
    uint32_t MapOfValues[256];
    for (int m = 0; m < 256; m++)
    {
        MapOfValues[m] = FastExponentiation((uint8_t)m, e, n);
    }

    uint32_t C = 0;
    int16_t M = 0;

    while (fscanf(EncryptedFile_ptr, "%8x", &C) == 1)
    {
        for (M = 0; M < 256; M++)
        {
            if (MapOfValues[M] == C)
            {
                fputc((uint8_t)M, stdout);
                break;
            }
        }
    }
}