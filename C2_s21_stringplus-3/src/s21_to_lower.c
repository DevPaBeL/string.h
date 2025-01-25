#include "s21_string.h"

void *s21_to_lower(const char *str) {
  char *res = S21_NULL;
  if (str != S21_NULL) {
    s21_size_t len = s21_strlen(str);
    res = malloc((len + 1) * sizeof(char));
    for (s21_size_t i = 0; i <= len; i++) {
      if (str[i] >= 'A' && str[i] <= 'Z') {
        res[i] = str[i] + 32;
      } else {
        res[i] = str[i];
      }
    }
  }

  return res;
}