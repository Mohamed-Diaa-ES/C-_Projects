#include <stdint.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct
{
    uint16_t p;
    uint16_t q;

} Q_P;
#define Prime 1
#define NOT_Prime 0

#define MAX_Specified 65535
#define MIN_Specified 32768
static uint64_t n = 0;
static const uint64_t e = 65537;
static uint64_t d = 0;

uint8_t is_Prime(uint64_t n)
{
    if (n <= 1 || n % 2 == 0 || n % 3 == 0)
        return NOT_Prime;
    if (n <= 3)
        return Prime;

    for (int i = 5; i * i <= n; i += 6)
    {
        if (((n % i) == 0) || ((n % (i + 2)) == 0))
            return NOT_Prime;
    }
    return Prime;
}

uint16_t random_ranged_16_bit(uint16_t low, uint16_t high)
{

    uint16_t result = (rand() % (high - low + 1)) + low;

    return result;
}

uint16_t random_prime_16Bit(uint16_t low, uint16_t high)
{
    uint16_t val = 0;
    while (!is_Prime(val))
    {

        val = random_ranged_16_bit(low, high);
    }
    return val;
}

Q_P Get_KeyGen_PrimePairs()
{
    uint16_t val1 = 0;
    uint16_t val2 = 0;
    val1 = random_prime_16Bit(MIN_Specified, MAX_Specified);
    val2 = val1;
    while (val2 == val1)
    {
        val2 = random_prime_16Bit(MIN_Specified, MAX_Specified);
    }
    Q_P Resultant_Pair = {val1, val2};
    return Resultant_Pair;
}

uint64_t Get_d_simple(uint64_t e_val, Q_P PrimePair)
{
    uint64_t phi_n = (PrimePair.p - 1) * (PrimePair.q - 1);

    for (uint64_t k = 1; k < e_val; k++)
    {
        if ((k * phi_n + 1) % e_val == 0)
        {
            return (k * phi_n + 1) / e_val;
        }
    }
    return 0;
}

void KeyGenAlgorithm()
{

    srand(time(NULL));

    FILE *PrivateKeyFileptr = fopen("Keys_Ciph_Plain_Files/Private_Key_File.txt", "W");
    FILE *PublicKeyFileptr = fopen("Keys_Ciph_Plain_Files/Public_Key_File.txt", "W");
}