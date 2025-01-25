#include "tests_suitcases.h"

START_TEST(strpbrk1) {
  const char *str1 = "Hello, world!";
  const char *str2 = "wor";
  const char *expected_result = strpbrk(str1, str2);
  const char *actual_result = s21_strpbrk(str1, str2);
  ck_assert_ptr_eq(actual_result, expected_result);
}
END_TEST

START_TEST(strpbrk2) {
  const char *str1 = "";
  const char *str2 = "abc";
  const char *expected_result = strpbrk(str1, str2);
  const char *actual_result = s21_strpbrk(str1, str2);
  ck_assert_ptr_eq(actual_result, expected_result);
}
END_TEST

START_TEST(strpbrk3) {
  const char *str1 = "Hello, world!";
  const char *str2 = "";
  const char *expected_result = strpbrk(str1, str2);
  const char *actual_result = s21_strpbrk(str1, str2);
  ck_assert_ptr_eq(actual_result, expected_result);
}
END_TEST

START_TEST(strpbrk4) {
  const char *str1 = "Hello, world!";
  const char *str2 = "xyz";
  const char *expected_result = strpbrk(str1, str2);
  const char *actual_result = s21_strpbrk(str1, str2);
  ck_assert_ptr_eq(actual_result, expected_result);
}
END_TEST

START_TEST(strpbrk5) {
  const char *str1 = "Hello, world!";
  const char *str2 = "H";
  const char *expected_result = strpbrk(str1, str2);
  const char *actual_result = s21_strpbrk(str1, str2);
  ck_assert_ptr_eq(actual_result, expected_result);
}
END_TEST

START_TEST(strpbrk6) {
  const char *str1 = "Hello, world!";
  const char *str2 = "lo";
  const char *expected_result = strpbrk(str1, str2);
  const char *actual_result = s21_strpbrk(str1, str2);
  ck_assert_ptr_eq(actual_result, expected_result);
}
END_TEST

START_TEST(strpbrk7) {
  const char *str1 = "aaaaa";
  const char *str2 = "aa";
  const char *expected_result = strpbrk(str1, str2);
  const char *actual_result = s21_strpbrk(str1, str2);
  ck_assert_ptr_eq(actual_result, expected_result);
}
END_TEST

Suite *suite_strpbrk(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_STRPBRK");
  tc = tcase_create("case_strpbrk");

  tcase_add_test(tc, strpbrk1);
  tcase_add_test(tc, strpbrk2);
  tcase_add_test(tc, strpbrk3);
  tcase_add_test(tc, strpbrk4);
  tcase_add_test(tc, strpbrk5);
  tcase_add_test(tc, strpbrk6);
  tcase_add_test(tc, strpbrk7);

  suite_add_tcase(s, tc);
  return s;
}