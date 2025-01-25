#include "s21_string.h"

s21_size_t s21_strlen(const char* s) {
  s21_size_t length = 0;
  for (; *(s + length); length++);
  return length;
}