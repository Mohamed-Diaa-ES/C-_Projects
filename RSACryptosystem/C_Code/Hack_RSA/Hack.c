/**
 * @details This file decrypts the file using two approaches first by mapping values  of 0 till 255 and second by brute force as it will just need small time
 *          as our code is doing small range of numbers as p and q are in the range of [32768, 65535] so we can use that by modern machines this can be done fast
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
FILE *EncryptedFile_ptr = NULL;
const char *HTTPMessage = "TestHTTPMessage/test_message.http";
typedef struct
{
    uint16_t p;
    uint16_t q;

} Q_P;
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
            result = ((__uint128_t)result * M_Mod_N) % n; // caused over flow of integers and some wierd problems os used this :)
        }
        M_Mod_N = ((__uint128_t)M_Mod_N * M_Mod_N) % n;
        e /= 2;
    }
    return (uint32_t)result;
}
uint64_t Get_d(uint64_t e_val, Q_P PrimePair) // from the key generation function
{
    uint64_t phi_n = (uint64_t)(PrimePair.p - 1) * (uint64_t)(PrimePair.q - 1);

    for (uint64_t k = 1; k < e_val; k++)
    {
        if ((k * phi_n + 1) % e_val == 0) // taking advatage that e*d is (phi(n)*integer +1)
        {
            return (k * phi_n + 1) / e_val;
        }
    }
    return 0;
}
void mapValuesMethod(uint64_t n, uint64_t e);
int8_t bruteForceMethod(uint64_t n, uint64_t e)
{
    uint16_t p, q;
    uint64_t d;
    for (p = 32767; p < 65535; p += 2) // skipping even numbers
    {
        if (n % p == 0)
        {
            q = n / p;
            break;
        }
    }
    Q_P valOfPrimePair = {p, q};
    d = Get_d(e, valOfPrimePair);
    uint32_t C = 0;
    uint8_t M = 0;

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
void hackUsingPublicKeyFile(FILE *PublicKeyFile);
int main(int argc, char **argv)
{

    if (argc < 3)
    {
    Exit: // by the way I meant to use the goto statement because I want to. :)
        printf("NotSuffcient Number Of Files and paramters Or wrong caseletter!\n");
        printf("Must be in the Form of: \n");
        printf("./hack <public_key_file> <encrypted_file> \n");
        printf("Example: ./hack public_key.txt encrypted.txt \n");
        return 1;
    }
    else
    {
        FILE *PublicKeyFile_ptr = fopen(argv[1], "rb");
        if (PublicKeyFile_ptr == NULL)
        {
            perror("Error opening Public key file");

            return 1;
        }
        EncryptedFile_ptr = fopen(argv[2], "r");
        if (EncryptedFile_ptr == NULL)
        {
            perror("Error opening Encrypted Result file");
            fclose(PublicKeyFile_ptr);
            return 1;
        }
        // FILE *HTTPMessage_ptr = fopen(HTTPMessage, "wb");
        // // checking the files are readble
        // if (HTTPMessage_ptr == NULL)
        // {
        //     perror("Error opening Plain Text File file");
        //     fclose(PublicKeyFile_ptr);
        //     fclose(EncryptedFile_ptr);
        //     return 1;
        // }
        hackUsingPublicKeyFile(PublicKeyFile_ptr);
    }
    return 0;
}

void hackUsingPublicKeyFile(FILE *PublicKeyFile)
{
    if (EncryptedFile_ptr == NULL)
    {
        perror("Error opening Encrypted Result file");
        fclose(PublicKeyFile);

    }
    char buffer[64];
    uint64_t e;
    uint64_t n;

    if (fgets(buffer, sizeof(buffer), PublicKeyFile) != NULL)
    {
        n = strtoull(buffer, NULL, 10);
    }
    else
    {
        printf("ERROR READING ( n ) IN THE PUBLIC KEY FILE!!");
        printf("\nFILE MAY BE EMPTY! GENERATE THE NUMBERS FIRST!\n");
    }

    if (fgets(buffer, sizeof(buffer), PublicKeyFile) != NULL)
    {
        e = strtoull(buffer, NULL, 10);
    }
    else
    {
        printf("ERROR READING ( e ) IN THE PUBLIC KEY FILE!!");
        printf("\nFILE MAY BE EMPTY! GENERATE THE NUMBERS FIRST!\n");
    }
    bruteForceMethod(n,e);
}
/**
 * commands to compile
gcc Hack.c -o hack.exe
./hack.exe ../RSA_Code/Keys_Ciph_Plain_Files/Public_Key_File.txt ../RSA_Code/Results/Encrypted.hex
 * 
 */