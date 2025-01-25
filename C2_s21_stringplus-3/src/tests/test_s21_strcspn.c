#include "tests_suitcases.h"

START_TEST(strcspn1) {
  const char *str1 = "hello world";
  const char *str2 = "o";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn2) {
  const char *str1 = "";
  const char *str2 = "abc";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn3) {
  const char *str1 = "abcdefg";
  const char *str2 = "xyz";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn4) {
  const char *str1 = "hello world";
  const char *str2 = "he";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn5) {
  const char *str1 = "hello world";
  const char *str2 = "lo";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn6) {
  const char *str1 = "hello world";
  const char *str2 = "ld";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn7) {
  const char *str1 = "hello\0world";
  const char *str2 = "o";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn8) {
  const char *str1 = "hello\nworld";
  const char *str2 = "\n";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

Suite *suite_strcspn(void) {
  Suite *s = suite_create("s21_STRCSPN");
  TCase *tc = tcase_create("case_strcspn");

  tcase_add_test(tc, strcspn1);
  tcase_add_test(tc, strcspn2);
  tcase_add_test(tc, strcspn3);
  tcase_add_test(tc, strcspn4);
  tcase_add_test(tc, strcspn5);
  tcase_add_test(tc, strcspn6);
  tcase_add_test(tc, strcspn7);
  tcase_add_test(tc, strcspn8);
  suite_add_tcase(s, tc);
  return s;
}
