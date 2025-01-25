#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *res = S21_NULL;
  if (src != S21_NULL && str != S21_NULL) {
    s21_size_t len1 = s21_strlen(src);
    if (start_index <= len1) {
      s21_size_t len2 = s21_strlen(str);
      s21_size_t len = len1 + len2;
      res = malloc((len + 1) * sizeof(char));
      for (s21_size_t i = 0; i <= len; i++) {
        if (i < start_index) {
          res[i] = src[i];
        } else if (i >= start_index && i < start_index + len2) {
          res[i] = str[i - start_index];
        } else {
          res[i] = src[i - len2];
        }
      }
    }
  }

  return res;
}