#include <stdint.h>
#include <time.h>
#include <stdlib.h>
typedef struct
{
    uint16_t p;
    uint16_t q;

} Q_P;
#define Prime 1
#define NOT_Prime 0

#define MAX_Specified 65535
#define MIN_Specified 32768

uint8_t is_Prime(uint64_t n)
{
    if (n <= 1 || n % 2 == 0 || n % 3 == 0)
        return NOT_Prime;
    if (n <= 3)
        return Prime;

    for (int i = 0; i * i <= n; i += 6)
    {
        if (((n % i) == 0) || ((n % (i + 2)) == 0))
            return NOT_Prime;
    }
    return Prime;
}

uint16_t random_ranged_16_bit(uint16_t low, uint16_t high)
{

    srand(time(NULL));

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

