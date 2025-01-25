#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t i = 0;
  while (str1[i]) {
    int found = 0;
    for (int j = 0; str2[j]; j++) {
      if (str1[i] == str2[j]) {
        found = 1;
        break;
      }
    }
    if (found) {
      return i;
    }
    i++;
  }
  return i;
}