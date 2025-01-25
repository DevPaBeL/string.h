#include "tests_suitcases.h"

START_TEST(hello) {
  char *s = "Hello, world!";
  s21_size_t n_bytes = 10;
  char origin[n_bytes];
  char my[n_bytes];

  memcpy(origin, s, n_bytes);
  s21_memcpy(my, s, n_bytes);

  ck_assert_mem_eq(origin, my, n_bytes);
}
END_TEST

START_TEST(zero_n) {
  char *s = "Hello, world!";
  s21_size_t n_bytes = 0;
  char origin[n_bytes];
  char my[n_bytes];

  memcpy(origin, s, n_bytes);
  s21_memcpy(my, s, n_bytes);

  ck_assert_mem_eq(origin, my, n_bytes);
}
END_TEST

START_TEST(big_n) {
  char *s = "Hello, world!";
  s21_size_t n_bytes = 300;
  char origin[n_bytes];
  char my[n_bytes];

  memcpy(origin, s, n_bytes);
  s21_memcpy(my, s, n_bytes);

  ck_assert_mem_eq(origin, my, n_bytes);
}
END_TEST

START_TEST(array) {
  int arr[10] = {1, 2, 3, 4, 5, 30, 50, 60, 99, 100};
  s21_size_t n_bytes = 3;
  int origin[n_bytes];
  int my[n_bytes];

  memcpy(origin, arr, n_bytes);
  s21_memcpy(my, arr, n_bytes);

  ck_assert_mem_eq(origin, my, n_bytes);
}
END_TEST

START_TEST(empty) {
  char *s = "";
  s21_size_t n_bytes = 10;
  char origin[n_bytes];
  char my[n_bytes];

  memcpy(origin, s, n_bytes);
  s21_memcpy(my, s, n_bytes);

  ck_assert_mem_eq(origin, my, n_bytes);
}
END_TEST

Suite *suite_memcpy(void) {
  Suite *s = suite_create("suite_memcpy");
  TCase *tc = tcase_create("memcpy_tc");

  tcase_add_test(tc, hello);
  tcase_add_test(tc, zero_n);
  tcase_add_test(tc, big_n);
  tcase_add_test(tc, array);
  tcase_add_test(tc, empty);

  suite_add_tcase(s, tc);

  return s;
}
