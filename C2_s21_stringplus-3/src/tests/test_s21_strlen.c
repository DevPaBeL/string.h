#include "tests_suitcases.h"

START_TEST(hello) {
  char *s = "Hello, world!";

  ck_assert_int_eq(strlen(s), s21_strlen(s));
}
END_TEST

START_TEST(empty) {
  char *s = "";

  ck_assert_int_eq(strlen(s), s21_strlen(s));
}
END_TEST

START_TEST(slash_zero) {
  char *s = "johrjfciajfjeggh\0fjdfkj";

  ck_assert_int_eq(strlen(s), s21_strlen(s));
}
END_TEST

START_TEST(numbers) {
  char *s = "12350ddgdghlmlkm546,gfgh35";

  ck_assert_int_eq(strlen(s), s21_strlen(s));
}
END_TEST

START_TEST(space) {
  char *s = "           ";

  ck_assert_int_eq(strlen(s), s21_strlen(s));
}
END_TEST

Suite *suite_strlen(void) {
  Suite *s = suite_create("suite_strlen");
  TCase *tc = tcase_create("strlen_tc");

  tcase_add_test(tc, hello);
  tcase_add_test(tc, empty);
  tcase_add_test(tc, slash_zero);
  tcase_add_test(tc, numbers);
  tcase_add_test(tc, space);

  suite_add_tcase(s, tc);

  return s;
}
