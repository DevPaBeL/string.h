#include "tests_suitcases.h"

START_TEST(strrchr1) {
  const char *str = "hello, world!";
  int c = 'l';
  const char *expected = strrchr(str, c);
  const char *actual = s21_strrchr(str, c);
  ck_assert_ptr_eq(expected, actual);
}
END_TEST

START_TEST(strrchr2) {
  const char *str = "hello, world!";
  int c = 'z';
  const char *expected = strrchr(str, c);
  const char *actual = s21_strrchr(str, c);
  ck_assert_ptr_eq(expected, actual);
}
END_TEST

START_TEST(strrchr3) {
  const char *str = "hello, world!";
  int c = '!';
  const char *expected = strrchr(str, c);
  const char *actual = s21_strrchr(str, c);
  ck_assert_ptr_eq(expected, actual);
}
END_TEST

START_TEST(strrchr4) {
  const char *str = "aaa";
  int c = 'a';
  const char *expected = strrchr(str, c);
  const char *actual = s21_strrchr(str, c);
  ck_assert_ptr_eq(expected, actual);
}
END_TEST

START_TEST(strrchr5) {
  const char *str = "";
  int c = 'a';
  const char *expected = strrchr(str, c);
  const char *actual = s21_strrchr(str, c);
  ck_assert_ptr_eq(expected, actual);
}
END_TEST

START_TEST(strrchr6) {
  const char *str = "hello, world!";
  int c = '\0';
  const char *expected = strrchr(str, c);
  const char *actual = s21_strrchr(str, c);
  ck_assert_ptr_eq(expected, actual);
}
END_TEST

START_TEST(strrchr7) {
  const char *str = "abracadabra";
  int c = 'd';
  const char *expected = strrchr(str, c);
  const char *actual = s21_strrchr(str, c);
  ck_assert_ptr_eq(expected, actual);
}
END_TEST

Suite *suite_strrchr(void) {
  Suite *s = suite_create("s21_STRRCHR");
  TCase *tc = tcase_create("case_strrchr");

  tcase_add_test(tc, strrchr1);
  tcase_add_test(tc, strrchr2);
  tcase_add_test(tc, strrchr3);
  tcase_add_test(tc, strrchr4);
  tcase_add_test(tc, strrchr5);
  tcase_add_test(tc, strrchr6);
  tcase_add_test(tc, strrchr7);

  suite_add_tcase(s, tc);
  return s;
}
