#include "tests_suitcases.h"

START_TEST(different_letters) {
  char *s = "HeLlo";
  char *lower = s21_to_lower(s);
  char *expected = "hello";

  ck_assert_str_eq(lower, expected);

  free(lower);
}
END_TEST

START_TEST(small_letters) {
  char *s = "hello";
  char *lower = s21_to_lower(s);
  char *expected = "hello";

  ck_assert_str_eq(lower, expected);

  free(lower);
}
END_TEST

START_TEST(big_letters) {
  char *s = "HELLO";
  char *lower = s21_to_lower(s);
  char *expected = "hello";

  ck_assert_str_eq(lower, expected);

  free(lower);
}
END_TEST

START_TEST(empty) {
  char *s = "";
  char *lower = s21_to_lower(s);
  char *expected = "";

  ck_assert_str_eq(lower, expected);

  free(lower);
}
END_TEST

Suite *suite_to_lower(void) {
  Suite *s = suite_create("s21_suite_to_lower");
  TCase *tc = tcase_create("to_lower_tc");

  tcase_add_test(tc, different_letters);
  tcase_add_test(tc, small_letters);
  tcase_add_test(tc, big_letters);
  tcase_add_test(tc, empty);

  suite_add_tcase(s, tc);

  return s;
}