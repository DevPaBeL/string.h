#include "s21_string.h"

int s21_memcmp(const void *s1, const void *s2, s21_size_t n) {
  unsigned char *p1 = (unsigned char *)s1;
  unsigned char *p2 = (unsigned char *)s2;
  int res = 0;

  for (s21_size_t i = 0; i < n && res == 0; i++, p1++, p2++) {
    res = *p1 - *p2;
  }
  return res;
}