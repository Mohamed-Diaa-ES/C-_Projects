#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "Decrypt.h"

static const char *EncryptedFilePath = "Results/Encrypted.hex";
const char *PlainTextFile = "Results/PlainText_Result.txt";
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
            result = (result * M_Mod_N) % n;
        }
        M_Mod_N = (M_Mod_N * M_Mod_N) % n;
        e /= 2;
    }
    return (uint32_t)result;
}

void DecryptionAlgorithm(const char *PrivateKeyFilePath)
{
    // reading the files
    FILE *PrivateKeyFile_ptr = fopen(PrivateKeyFilePath, "r");
    if (PrivateKeyFile_ptr == NULL)
    {
        perror("Error opening Public key file");

        return;
    }
    FILE *EncryptedFile_ptr = fopen(EncryptedFilePath, "r");
    if (EncryptedFile_ptr == NULL)
    {
        perror("Error opening Encrypted Result file");
        fclose(PrivateKeyFile_ptr);
        return;
    }
    FILE *PlainTextFile_ptr = fopen(PlainTextFile, "w");
    // checking the files are readble
    if (PlainTextFile_ptr == NULL)
    {
        perror("Error opening Plain Text File file");
        fclose(PrivateKeyFile_ptr);
        fclose(EncryptedFile_ptr);
        return;
    }
    // creating the receiving buffers and vars
    char buffer[64];
    uint64_t d;
    uint64_t n;

    if (fgets(buffer, sizeof(buffer), PrivateKeyFile_ptr) != NULL)
    {
        d = strtoull(buffer, NULL, 10);
    }
    else
    {
        printf("ERROR READING ( d ) IN THE PUBLIC KEY FILE!!");
        printf("\nFILE MAY BE EMPTY! GENERATE THE NUMBERS FIRST!\n");
    }

    if (fgets(buffer, sizeof(buffer), PrivateKeyFile_ptr) != NULL)
    {
        n = strtoull(buffer, NULL, 10);
    }
    else
    {
        printf("ERROR READING ( n ) IN THE PUBLIC KEY FILE!!");
        printf("\nFILE MAY BE EMPTY! GENERATE THE NUMBERS FIRST!\n");
    }
    uint32_t C = 0;
    uint8_t M = 0;

    while (fscanf(EncryptedFile_ptr, "%8x", &C) == 1)
    {

        M = FastExponentiation_decrypt(C, d, n);
        fputc(M, PlainTextFile_ptr);
    }

    printf("n is:%llu\n", n);
    printf("d is:%llu\n", d);
    fclose(PlainTextFile_ptr);
    fclose(EncryptedFile_ptr);
    fclose(PrivateKeyFile_ptr);
}

