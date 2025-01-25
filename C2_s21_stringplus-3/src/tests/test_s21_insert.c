#include "tests_suitcases.h"

START_TEST(inside) {
  char *src = "He world";
  char *str = "llo";
  char *ins = s21_insert(src, str, 2);
  char *expected = "Hello world";

  ck_assert_str_eq(ins, expected);

  free(ins);
}
END_TEST

START_TEST(begin) {
  char *src = " world";
  char *str = "Hello";
  char *ins = s21_insert(src, str, 0);
  char *expected = "Hello world";

  ck_assert_str_eq(ins, expected);

  free(ins);
}
END_TEST

START_TEST(end) {
  char *src = "He";
  char *str = "llo";
  char *ins = s21_insert(src, str, 2);
  char *expected = "Hello";

  ck_assert_str_eq(ins, expected);

  free(ins);
}
END_TEST

START_TEST(emptysrc) {
  char *src = "";
  char *str = "Hello";
  char *ins = s21_insert(src, str, 0);
  char *expected = "Hello";

  ck_assert_str_eq(ins, expected);

  free(ins);
}
END_TEST

START_TEST(emptystr) {
  char *src = "Hello";
  char *str = "";
  char *ins = s21_insert(src, str, 2);
  char *expected = "Hello";

  ck_assert_str_eq(ins, expected);

  free(ins);
}
END_TEST

Suite *suite_to_insert(void) {
  Suite *s = suite_create("suite_to_insert");
  TCase *tc = tcase_create("s21_to_insert_tc");

  tcase_add_test(tc, inside);
  tcase_add_test(tc, begin);
  tcase_add_test(tc, end);
  tcase_add_test(tc, emptysrc);
  tcase_add_test(tc, emptystr);

  suite_add_tcase(s, tc);

  return s;
}