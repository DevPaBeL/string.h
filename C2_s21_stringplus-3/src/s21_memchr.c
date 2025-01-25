#include "s21_string.h"

void *s21_memchr(const void *s, int c, s21_size_t n) {
  unsigned char *p = (unsigned char *)s;
  for (; *p != (unsigned char)c && n > 0; p++, n--);
  return (n > 0) ? (void *)p : S21_NULL;
}