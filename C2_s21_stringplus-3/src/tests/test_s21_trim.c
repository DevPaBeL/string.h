#include "tests_suitcases.h"

START_TEST(notrim) {
  char *s = "!hoohellohhh!";
  char *trim_chars = "ho";
  char *trim = s21_trim(s, trim_chars);
  char *expected = "!hoohellohhh!";

  ck_assert_str_eq(trim, expected);

  free(trim);
}
END_TEST

START_TEST(ltrim) {
  char *s = "hoohellohhh!";
  char *trim_chars = "ho";
  char *trim = s21_trim(s, trim_chars);
  char *expected = "ellohhh!";

  ck_assert_str_eq(trim, expected);

  free(trim);
}
END_TEST

START_TEST(rtrim) {
  char *s = "!hoohellohhh";
  char *trim_chars = "ho";
  char *trim = s21_trim(s, trim_chars);
  char *expected = "!hoohell";

  ck_assert_str_eq(trim, expected);

  free(trim);
}
END_TEST

START_TEST(twotrim) {
  char *s = "hoohellohhh";
  char *trim_chars = "ho";
  char *trim = s21_trim(s, trim_chars);
  char *expected = "ell";

  ck_assert_str_eq(trim, expected);

  free(trim);
}
END_TEST

START_TEST(alltrim) {
  char *s = "hoohhh";
  char *trim_chars = "ho";
  char *trim = s21_trim(s, trim_chars);
  char *expected = "";

  ck_assert_str_eq(trim, expected);

  free(trim);
}
END_TEST

START_TEST(empty) {
  char *s = "";
  char *trim_chars = "";
  char *trim = s21_trim(s, trim_chars);
  char *expected = "";

  ck_assert_str_eq(trim, expected);

  free(trim);
}
END_TEST

Suite *suite_trim(void) {
  Suite *s = suite_create("s21_suite_trim");
  TCase *tc = tcase_create("trim_tc");

  tcase_add_test(tc, notrim);
  tcase_add_test(tc, ltrim);
  tcase_add_test(tc, rtrim);
  tcase_add_test(tc, twotrim);
  tcase_add_test(tc, alltrim);
  tcase_add_test(tc, empty);

  suite_add_tcase(s, tc);

  return s;
}
