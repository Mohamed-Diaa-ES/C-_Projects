
#ifndef Decrypt_H
#define Decrypt_H

uint32_t FastExponentiation(uint64_t C, uint64_t e, uint64_t n);
void DecryptionAlgorithm(const char *PrivateKeyFilePath);

#endif