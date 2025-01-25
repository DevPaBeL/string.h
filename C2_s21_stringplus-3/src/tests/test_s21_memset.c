#include "tests_suitcases.h"

START_TEST(gj) {
  char s[] = "Gamarjoba!";
  s21_size_t n_bytes = 5;
  int c = 'o';

  ck_assert_mem_eq(memset(s, c, n_bytes), s21_memset(s, c, n_bytes), n_bytes);
}
END_TEST

START_TEST(int_array_c) {
  int s[] = {1, 2, 3, 4, 5, 6, 999, 0};
  s21_size_t n_bytes = 8;
  int c = 'o';

  ck_assert_mem_eq(memset(s, c, n_bytes), s21_memset(s, c, n_bytes), n_bytes);
}
END_TEST

START_TEST(int_array_n) {
  int s[] = {1, 2, 3, 4, 5, 6, 999, 0};
  s21_size_t n_bytes = 8;
  int c = 0;

  ck_assert_mem_eq(memset(s, c, n_bytes), s21_memset(s, c, n_bytes), n_bytes);
}
END_TEST

START_TEST(zero_n) {
  char s[] = "I am really excited to study at School 21";
  s21_size_t n_bytes = 0;
  int c = 9;

  ck_assert_mem_eq(memset(s, c, n_bytes), s21_memset(s, c, n_bytes), n_bytes);
}
END_TEST

Suite *suite_memset(void) {
  Suite *s = suite_create("suite_memset");
  TCase *tc = tcase_create("memset_tc");

  tcase_add_test(tc, gj);
  tcase_add_test(tc, int_array_c);
  tcase_add_test(tc, int_array_n);
  tcase_add_test(tc, zero_n);

  suite_add_tcase(s, tc);

  return s;
}
