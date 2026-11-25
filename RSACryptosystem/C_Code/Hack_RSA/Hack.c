#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "Brute/Brute.h"
#include "MapValues/mapping_values.h"

void hackUsingPublicKeyFile(FILE *PublicKeyFile, FILE *EncryptedFile_ptr);

int main(int argc, char **argv)
{
    if (argc != 3)
    {
    Exit:
        fprintf(stderr, "NotSuffcient Number Of Files and paramters Or wrong caseletter!\n");
        fprintf(stderr, "Must be in the Form of: \n");
        fprintf(stderr, "./hack <public_key_file> <encrypted_file> \n");
        fprintf(stderr, "Example: ./hack public_key.txt encrypted.txt \n");
        return 1;
    }

    FILE *PublicKeyFile_ptr = fopen(argv[1], "r");
    if (PublicKeyFile_ptr == NULL)
    {
        perror("Error opening Public key file");
        return 1;
    }

    FILE *EncryptedFile_ptr = fopen(argv[2], "r");
    if (EncryptedFile_ptr == NULL)
    {
        perror("Error opening Encrypted Result file");
        fclose(PublicKeyFile_ptr);
        return 1;
    }

    hackUsingPublicKeyFile(PublicKeyFile_ptr, EncryptedFile_ptr);

    fclose(PublicKeyFile_ptr);
    fclose(EncryptedFile_ptr);
    return 0;
}

void hackUsingPublicKeyFile(FILE *PublicKeyFile, FILE *EncryptedFile_ptr)
{
    char buffer[64];
    uint64_t e = 0;
    uint64_t n = 0;

    if (fgets(buffer, sizeof(buffer), PublicKeyFile) != NULL)
    {
        n = strtoull(buffer, NULL, 10);
    }
    else
    {
        fprintf(stderr, "ERROR READING ( n ) IN THE PUBLIC KEY FILE!!\n");
        fprintf(stderr, "FILE MAY BE EMPTY! GENERATE THE NUMBERS FIRST!\n");
        exit(1);
    }

    if (fgets(buffer, sizeof(buffer), PublicKeyFile) != NULL)
    {
        e = strtoull(buffer, NULL, 10);
    }
    else
    {
        fprintf(stderr, "ERROR READING ( e ) IN THE PUBLIC KEY FILE!!\n");
        fprintf(stderr, "FILE MAY BE EMPTY! GENERATE THE NUMBERS FIRST!\n");
        exit(1);
    }

    printf("\nbruteForceMethod\n");
    bruteForceMethod(EncryptedFile_ptr, n, e);

    rewind(EncryptedFile_ptr);

    printf("\nmapValuesMethod\n");
    mapValuesMethod(EncryptedFile_ptr, n, e);
}