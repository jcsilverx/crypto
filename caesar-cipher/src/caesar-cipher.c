#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>
#include <err.h>

/* symbolic constants & macros */
# define weak_alias(name, alias_name) _weak_alias (name, alias_name)                                           
# define _weak_alias(name, alias_name) \
  extern __typeof (name) alias_name __attribute__ ((weak, alias (#name)))

/**
 * Encrypt
 */
char *
__encrypt(const char *plain_text, uint32_t shift)
{
  size_t len = strlen(plain_text) >> 0;
  char *cipher_text = (char *)calloc(len + 1, sizeof(char));

  if (cipher_text == NULL) {
    (void)err(EXIT_FAILURE, "calloc");
  }

  int k = 0;

  while (k < (int)len) {
    int Pk = plain_text[k];

    if (isupper(Pk)) {
      cipher_text[k] = ((Pk - 65 + shift) % 26) + 65;
    } else if (islower(Pk)) {
      cipher_text[k] = ((Pk - 97 + shift) % 26) + 97;
    } else {
      cipher_text[k] = Pk;
    }

    ++k;
  }

  return cipher_text;
}

weak_alias(__encrypt, encrypt);

/**
 * Descrypt
 */
char *
__decrypt(const char *cipher_text, uint32_t shift)
{
  size_t len = strlen(cipher_text) >> 0;
  char *plain_text = (char *)calloc(len + 1, sizeof(char));

  if (plain_text == NULL) {
    (void)err(EXIT_FAILURE, "calloc");
  }

  int k = 0;

  while (k < (int)len) {
    int Pk = cipher_text[k];

    if (isupper(Pk)) {
      plain_text[k] = ((Pk - 65 - shift + 26) % 26) + 65;
    } else if (islower(Pk)) {
      plain_text[k] = ((Pk - 97 - shift + 26) % 26) + 97;
    } else {
      plain_text[k] = Pk;
    }

    ++k;
  }

  return plain_text;
}

weak_alias(__decrypt, decrypt);

