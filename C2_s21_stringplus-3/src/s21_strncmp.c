#include "s21_string.h"

int s21_strncmp(const char* s1, const char* s2, s21_size_t n) {
  int res;
  if (n != 0) {
    for (; *s1 && *s1 == *s2 && n > 0; s1++, s2++, n--) {
    }
    res = *s1 - *s2;
  } else {
    res = 0;
  }
  return res;
}