#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *res = S21_NULL;
  if (src != S21_NULL && trim_chars != S21_NULL) {
    s21_size_t end = s21_strlen(src);
    s21_size_t begin = 0;
    while (s21_strrchr(trim_chars, src[begin]) && begin < end) begin++;

    while (s21_strrchr(trim_chars, src[end - 1]) && begin < end) end--;

    res = malloc((end - begin + 1) * sizeof(char));

    for (s21_size_t i = begin; i < end; i++) {
      res[i - begin] = src[i];
    }

    res[end - begin] = '\0';
  }

  return res;
}