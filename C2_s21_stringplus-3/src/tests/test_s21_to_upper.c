#include "tests_suitcases.h"

START_TEST(different_letters) {
  char *s = "HeLlo";
  char *upper = s21_to_upper(s);
  char *expected = "HELLO";

  ck_assert_str_eq(upper, expected);

  free(upper);
}
END_TEST

START_TEST(small_letters) {
  char *s = "hello";
  char *upper = s21_to_upper(s);
  char *expected = "HELLO";

  ck_assert_str_eq(upper, expected);

  free(upper);
}
END_TEST

START_TEST(big_letters) {
  char *s = "HELLO";
  char *upper = s21_to_upper(s);
  char *expected = "HELLO";

  ck_assert_str_eq(upper, expected);

  free(upper);
}
END_TEST

START_TEST(empty) {
  char *s = "";
  char *upper = s21_to_upper(s);
  char *expected = "";

  ck_assert_str_eq(upper, expected);

  free(upper);
}
END_TEST

Suite *suite_to_upper(void) {
  Suite *s = suite_create("suite_to_upper");
  TCase *tc = tcase_create("to_upper_tc");

  tcase_add_test(tc, different_letters);
  tcase_add_test(tc, small_letters);
  tcase_add_test(tc, big_letters);
  tcase_add_test(tc, empty);

  suite_add_tcase(s, tc);

  return s;
}
