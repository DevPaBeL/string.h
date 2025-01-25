#include "s21_string.h"

char *s21_strchr(const char *s, int c) {
  char *p = (char *)s;
  for (; *p != (unsigned char)c && *p; p++) {
  }
  return (*p == (unsigned char)c) ? p : S21_NULL;
}