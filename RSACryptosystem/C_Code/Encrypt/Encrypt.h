
#ifndef Encrypt_H
#define Encrypt_H

uint32_t FastExponentiation(uint8_t m, uint64_t e, uint64_t n);
void EncryptionAlgorithm(const char *PublicKeyFilePath, const char *SecretFilePath, const char *EncryptedFilePath);

#endif