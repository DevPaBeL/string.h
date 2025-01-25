#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *saveptr = S21_NULL;
  char *token;
  if (str == S21_NULL) {
    str = saveptr;
    if (str == S21_NULL) {
      return S21_NULL;
    }
  }
  if (*delim == '\0') {
    return S21_NULL;
  }
  while (*str != '\0' && s21_strchr(delim, *str)) {
    str++;
  }

  if (*str == '\0') {
    saveptr = S21_NULL;
    return S21_NULL;
  }
  token = str;
  while (*str != '\0' && !s21_strchr(delim, *str)) {
    str++;
  }

  if (*str != '\0') {
    *str++ = '\0';
    saveptr = str;
  } else {
    saveptr = S21_NULL;
  }

  return token;
}