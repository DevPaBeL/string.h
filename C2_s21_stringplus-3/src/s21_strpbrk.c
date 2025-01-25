#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *out = S21_NULL;
  int found = 0;

  for (const char *a = str1; *a && !found; a++) {
    for (const char *b = str2; *b && !found; b++) {
      if (*a == *b) {
        out = (char *)a;
        found = 1;
      }
    }
  }
  return out;
}