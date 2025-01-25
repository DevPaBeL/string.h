#include "tests_suitcases.h"

START_TEST(strncat1) {
  char dest[100];
  char src[] = "world";
  s21_size_t n = 5;

  strcpy(dest, "hello ");
  ck_assert_str_eq(s21_strncat(dest, src, n), "hello world");
}
END_TEST

START_TEST(strncat2) {
  char dest[100];
  char src[] = "world";
  s21_size_t n = 2;

  strcpy(dest, "hello ");
  ck_assert_str_eq(s21_strncat(dest, src, n), "hello wo");
}
END_TEST

START_TEST(strncat3) {
  char dest[100];
  char src[] = "world";
  s21_size_t n = 0;

  strcpy(dest, "hello ");
  ck_assert_str_eq(s21_strncat(dest, src, n), "hello ");
}
END_TEST

START_TEST(strncat4) {
  char dest[100];
  char src[] = "";
  s21_size_t n = 10;

  strcpy(dest, "hello ");
  ck_assert_str_eq(s21_strncat(dest, src, n), "hello ");
}
END_TEST

START_TEST(strncat5) {
  char dest[100] = {0};
  char src[] = "world";
  s21_size_t n = 5;

  ck_assert_str_eq(s21_strncat(dest, src, n), "world");
}
END_TEST

START_TEST(strncat6) {
  char dest[100];
  char src[] = "world";
  s21_size_t n = strlen(src);

  strcpy(dest, "hello ");
  ck_assert_str_eq(s21_strncat(dest, src, n), "hello world");
}
END_TEST

Suite *suite_strncat(void) {
  Suite *s = suite_create("s21_STRNCAT");
  TCase *tc = tcase_create("case_strncat");

  tcase_add_test(tc, strncat1);
  tcase_add_test(tc, strncat2);
  tcase_add_test(tc, strncat3);
  tcase_add_test(tc, strncat4);
  tcase_add_test(tc, strncat5);
  tcase_add_test(tc, strncat6);

  suite_add_tcase(s, tc);

  return s;
}