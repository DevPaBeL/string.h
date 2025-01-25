#include "s21_string.h"

char *s21_strrchr(const char *s, int symbol) {
  char *result = S21_NULL;

  while (*s != '\0') {
    if (*s == symbol) result = (char *)s;
    s++;
  }
  if (*s == symbol) result = (char *)s;
  return result;
}