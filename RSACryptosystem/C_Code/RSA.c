#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "KeyGen/KeyGen.h"
#include "Encrypt/Encrypt.h"

int main(int argc, char **argv)
{

    if (argc < 4)
    {
    Exit:
        printf("NotSuffcient Number Of Files and paramters!\n");
        printf("Must be in the Form of: \n");
        printf("./rsa.exe operation <output_public_key_file><output_private_key_file> \n");
        printf("Example: ./rsa encrypt public_key.txt secret_text.txt encrypted.txt \n");
        return 0;
    }
    else
    {
        if (strcmp(argv[1], "keygen") == 0)
        {
            KeyGenAlgorithm(argv[2], argv[3]);
        }
        else if (argc == 5)
        {
            if (strcmp(argv[1], "encrypt") == 0)
            {
                EncryptionAlgorithm(argv[2], argv[3]);
            }
            else if (strcmp(argv[1], "decrypt") == 0)
            {
                // DecryptionAlgorithm(argv[2], argv[3]);
            }
            else
            {
                printf("Input Command is not applicable You may Check Your lower case or the word it self.");
            }
        }
        else
        {
            goto Exit;
        }
    }
}