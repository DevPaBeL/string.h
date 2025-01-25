#include "s21_string.h"

char *s21_strerror(int errnum) {
  static char str[MAX_MSG_SIZE] = {'\0'};

  if (errnum < 0 || errnum >= S21_ERRLIST_SIZE) {
    int i = UNERR_INDEX;
    s21_strncpy(str, UNKNOWN_ERROR, MAX_MSG_SIZE);

    if (errnum == -2147483648) {
      s21_strncat(str, "-2147483648", MAX_MSG_SIZE);
    } else if (errnum < 0) {
      s21_strncat(str, "-", MAX_MSG_SIZE);
      errnum = -errnum;
      i++;
    }
    if (errnum != -2147483648) {
      int int_size = 0;
      int errnum_dub;
      errnum_dub = errnum;
      while (errnum_dub) {
        errnum_dub /= 10;
        int_size++;
      }
      int j = i + int_size - 1;
      while (errnum) {
        str[j] = errnum % 10 + '0';
        errnum /= 10;
        j--;
      }
      str[i + int_size] = '\0';
    }
  } else {
    s21_strncpy(str, s21_err_list[errnum], MAX_MSG_SIZE);
  }
  return str;
}