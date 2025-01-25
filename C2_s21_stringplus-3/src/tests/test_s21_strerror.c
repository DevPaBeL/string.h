#include "tests_suitcases.h"

START_TEST(strerror_1) {
  for (int i = 0; i < S21_ERRLIST_SIZE; i++) {
    ck_assert_str_eq(s21_strerror(i), s21_err_list[i]);
  }
}
END_TEST

START_TEST(strerror_2) {
  ck_assert_str_eq(s21_strerror(-2147483648), UNKNOWN_ERROR_MIN);
}
END_TEST

START_TEST(strerror_3) {
  ck_assert_str_eq(s21_strerror(2147483647), UNKNOWN_ERROR_MAX);
}
END_TEST

START_TEST(strerror_4) {
  ck_assert_str_eq(s21_strerror(-256), UNKNOWN_ERROR_256);
}
END_TEST

Suite* suite_strerror(void) {
  Suite* s = suite_create("s21_STRERROR");
  TCase* tc = tcase_create("case_strerror");
  tcase_add_test(tc, strerror_1);
  tcase_add_test(tc, strerror_2);
  tcase_add_test(tc, strerror_3);
  tcase_add_test(tc, strerror_4);
  suite_add_tcase(s, tc);
  return s;
}