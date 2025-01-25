#include "tests_suitcases.h"

START_TEST(strstr1) {
  char haystack[] = "";
  char needle[] = "abc";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr2) {
  char haystack[] = "abababa";
  char needle[] = "aba";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr3) {
  char haystack[] = "abcdef";
  char needle[] = "f";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr4) {
  char haystack[] = "aaabbbccc";
  char needle[] = "bbb";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

Suite *suite_strstr(void) {
  Suite *s = suite_create("s21_STRSTR");
  TCase *tc = tcase_create("case_strstr");

  tcase_add_test(tc, strstr1);
  tcase_add_test(tc, strstr2);
  tcase_add_test(tc, strstr3);
  tcase_add_test(tc, strstr4);

  suite_add_tcase(s, tc);
  return s;
}
