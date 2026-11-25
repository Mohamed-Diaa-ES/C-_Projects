#ifndef MAPPING_VALUES_H
#define MAPPING_VALUES_H

#include <stdio.h>
#include <stdint.h>

uint32_t FastExponentiation(uint8_t m, uint64_t e, uint64_t n);
void mapValuesMethod(FILE *EncryptedFile_ptr, uint64_t n, uint64_t e);

#endif