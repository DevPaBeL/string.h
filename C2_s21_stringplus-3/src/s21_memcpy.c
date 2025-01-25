#include "s21_string.h"

void *s21_memcpy(void *d, const void *s, s21_size_t n) {
  unsigned char *dest = (unsigned char *)d;
  unsigned char *p = (unsigned char *)s;

  for (s21_size_t i = 0; i < n; i++) {
    dest[i] = p[i];
  }
  return dest;
}