#include "tests_suitcases.h"

START_TEST(strtok1) {
  char str[] = "This is a test school21";
  char *result = s21_strtok(str, " ");
  ck_assert_str_eq(result, "This");
  result = s21_strtok(S21_NULL, " ");
  ck_assert_str_eq(result, "is");
  result = s21_strtok(S21_NULL, " ");
  ck_assert_str_eq(result, "a");
  result = s21_strtok(S21_NULL, " ");
  ck_assert_str_eq(result, "test");
  result = s21_strtok(S21_NULL, " ");
  ck_assert_str_eq(result, "school21");
  result = s21_strtok(S21_NULL, " ");
  ck_assert_ptr_eq(result, S21_NULL);
}
END_TEST

START_TEST(strtok2) {
  char str[] = ",,,hello,,,world,,,,";
  char *result = s21_strtok(str, ",");
  ck_assert_str_eq(result, "hello");
  result = s21_strtok(S21_NULL, ",");
  ck_assert_str_eq(result, "world");
  result = s21_strtok(S21_NULL, ",");
  ck_assert_ptr_eq(result, S21_NULL);
}
END_TEST

START_TEST(strtok3) {
  char str[] = "1234567890";
  char *result = s21_strtok(str, "");
  ck_assert_ptr_eq(result, S21_NULL);
}
END_TEST

START_TEST(strtok4) {
  char str[] = " ";
  char *result = s21_strtok(str, " ");
  ck_assert_ptr_eq(result, S21_NULL);
}
END_TEST

START_TEST(strtok5) {
  char str[] = "multiple\tdelimiters\tsuch as space and tab";
  char *result = s21_strtok(str, " \t");
  ck_assert_str_eq(result, "multiple");
  result = s21_strtok(S21_NULL, " \t");
  ck_assert_str_eq(result, "delimiters");
  result = s21_strtok(S21_NULL, " \t");
  ck_assert_str_eq(result, "such");
  result = s21_strtok(S21_NULL, " \t");
  ck_assert_str_eq(result, "as");
  result = s21_strtok(S21_NULL, " \t");
  ck_assert_str_eq(result, "space");
  result = s21_strtok(S21_NULL, " \t");
  ck_assert_str_eq(result, "and");
  result = s21_strtok(S21_NULL, " \t");
  ck_assert_str_eq(result, "tab");
  result = s21_strtok(S21_NULL, " \t");
  ck_assert_ptr_eq(result, S21_NULL);
}
END_TEST

Suite *suite_strtok(void) {
  Suite *s = suite_create("s21_STRTOK");
  TCase *tc = tcase_create("case_strtok");

  tcase_add_test(tc, strtok1);
  tcase_add_test(tc, strtok2);
  tcase_add_test(tc, strtok3);
  tcase_add_test(tc, strtok4);
  tcase_add_test(tc, strtok5);

  suite_add_tcase(s, tc);
  return s;
}