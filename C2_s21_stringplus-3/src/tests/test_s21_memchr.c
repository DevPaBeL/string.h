#include "tests_suitcases.h"

START_TEST(hello) {
  unsigned char *s = (unsigned char *)"Hello, world!";

  ck_assert_ptr_eq(memchr(s, 'w', 10), s21_memchr(s, 'w', 10));
}
END_TEST

START_TEST(hello_NULL) {
  unsigned char *s = (unsigned char *)"Hello, world!";

  ck_assert_ptr_eq(memchr(s, 'i', 14), s21_memchr(s, 'i', 14));
}
END_TEST

START_TEST(zero_n) {
  unsigned char *s = (unsigned char *)"jkjfkffkdjgflkjdlkjfqirjtgbnkn";

  ck_assert_ptr_eq(memchr(s, 'i', 0), s21_memchr(s, 'i', 0));
}
END_TEST

START_TEST(number) {
  unsigned char *s = (unsigned char *)"6570514561";

  ck_assert_ptr_eq(memchr(s, '1', 11), s21_memchr(s, '1', 11));
}
END_TEST

START_TEST($symbol) {
  unsigned char *s = (unsigned char *)"How many old are $$you?";

  ck_assert_ptr_eq(memchr(s, 'u', 23), s21_memchr(s, 'u', 23));
}
END_TEST

START_TEST(empty) {
  unsigned char *s = (unsigned char *)"";

  ck_assert_ptr_eq(memchr(s, 'u', 1), s21_memchr(s, 'u', 1));
}
END_TEST

START_TEST(slash) {
  unsigned char *s = (unsigned char *)"Find\0 me";

  ck_assert_ptr_eq(memchr(s, 'e', 0), s21_memchr(s, 'e', 0));
}
END_TEST

START_TEST(small_n) {
  unsigned char *s = (unsigned char *)"Important warnings";

  ck_assert_ptr_eq(memchr(s, 'g', 5), s21_memchr(s, 'g', 5));
}
END_TEST

START_TEST(int_array) {
  int array[] = {1, 2, 3, 99, 100};

  ck_assert_ptr_eq(s21_memchr(array, 100, 20), memchr(array, 100, 20));
}
END_TEST

Suite *suite_memchr(void) {
  Suite *s = suite_create("suite_memchr");
  TCase *tc = tcase_create("memchr_tc");

  tcase_add_test(tc, hello);
  tcase_add_test(tc, hello_NULL);
  tcase_add_test(tc, zero_n);
  tcase_add_test(tc, number);
  tcase_add_test(tc, $symbol);
  tcase_add_test(tc, empty);
  tcase_add_test(tc, slash);
  tcase_add_test(tc, small_n);
  tcase_add_test(tc, int_array);

  suite_add_tcase(s, tc);

  return s;
}
