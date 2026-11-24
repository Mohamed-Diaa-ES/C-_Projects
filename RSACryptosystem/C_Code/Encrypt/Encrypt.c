#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "Encrypt.h"

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

void EncryptionAlgorithm(const char *PublicKeyFilePath, const char *SecretFilePath, const char *EncryptedFilePath)
{
    // reading the files
    FILE *PublicKeyFile_ptr = fopen(PublicKeyFilePath, "r");
    if (PublicKeyFile_ptr == NULL)
    {
        perror("Error opening Public key file");

        return;
    }
    FILE *EncryptedFile_ptr = fopen(EncryptedFilePath, "w");
    if (EncryptedFile_ptr == NULL)
    {
        perror("Error opening Encrypted Result file");
        fclose(PublicKeyFile_ptr);
        return;
    }
    FILE *SecretFile_ptr = fopen(SecretFilePath, "rb");
    // checking the files are readble
    if (SecretFile_ptr == NULL)
    {
        perror("Error opening Secret file");
        fclose(PublicKeyFile_ptr);
        fclose(EncryptedFile_ptr);
        return;
    }
    // creating the receiving buffers and vars
    char buffer[64];
    uint64_t e;
    uint64_t n;

    if (fgets(buffer, sizeof(buffer), PublicKeyFile_ptr) != NULL)
    {
        e = strtoull(buffer, NULL, 10);
    }
    else
    {
        printf("ERROR READING ( e ) IN THE PUBLIC KEY FILE!!");
        printf("\nFILE MAY BE EMPTY! GENERATE THE NUMBERS FIRST!\n");
    }

    if (fgets(buffer, sizeof(buffer), PublicKeyFile_ptr) != NULL)
    {
        n = strtoull(buffer, NULL, 10);
    }
    else
    {
        printf("ERROR READING ( n ) IN THE PUBLIC KEY FILE!!");
        printf("\nFILE MAY BE EMPTY! GENERATE THE NUMBERS FIRST!\n");
    }
    int ch;
    uint32_t C = 0;

    while ((ch = fgetc(SecretFile_ptr)) != EOF)
    {
        uint8_t m = (uint8_t)ch;
        C = FastExponentiation(m, e, n);
        fprintf(EncryptedFile_ptr, "%08X", C);
    }

    fclose(SecretFile_ptr);
    fclose(EncryptedFile_ptr);
    fclose(PublicKeyFile_ptr);
}
