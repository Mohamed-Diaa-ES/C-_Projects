
#ifndef Decrypt_H
#define Decrypt_H

uint32_t FastExponentiation_decrypt(uint64_t C, uint64_t e, uint64_t n);
void DecryptionAlgorithm(const char *PrivateKeyFilePath, const char *PlainTextFile, const char *EncryptedFilePath);
#endif