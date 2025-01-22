#ifndef CAESAR_CIPHER_H
#define CAESAR_CIPHER_H

#include <stdint.h>

extern char *encrypt(const char *plain_text, uint32_t shift);
extern char *decrypt(const char *cipher_text, uint32_t shift);

#endif