#include "tests_suitcases.h"

START_TEST(similar_strings) {
  char *s1 = "Hello, world!";
  char *s2 = "Hello, world!";

  ck_assert_int_eq(memcmp(s1, s2, 3), s21_memcmp(s1, s2, 3));
}
END_TEST

START_TEST(similar_array) {
  int array_1[] = {1, 2, 3, 99, 100};
  int array_2[] = {1, 2, 3, 99, 100};
  s21_size_t n = sizeof(int) * 5;

  ck_assert_int_eq(memcmp(array_1, array_2, n),
                   s21_memcmp(array_1, array_2, n));
}
END_TEST

START_TEST(zero_n) {
  char *s1 = "I am glad to see you, C!";
  char *s2 = "Hello, C!";

  ck_assert_int_eq(memcmp(s1, s2, 0), s21_memcmp(s1, s2, 0));
}
END_TEST

START_TEST(empty) {
  char *s1 = "";
  char *s2 = "Hello, C!";

  ck_assert_int_eq(memcmp(s1, s2, 1), s21_memcmp(s1, s2, 1));
}
END_TEST

START_TEST(strings) {
  char *s1 = "Hello, world!";
  char *s2 = "I am C programm";

  ck_assert_int_eq(memcmp(s1, s2, 14), s21_memcmp(s1, s2, 14));
}
END_TEST

START_TEST(array) {
  int array_1[] = {1, 2, 3, 99, 100};
  int array_2[] = {1, 2, 3, 100, 99};
  s21_size_t n = sizeof(int) * 5;

  ck_assert_int_eq(memcmp(array_1, array_2, n),
                   s21_memcmp(array_1, array_2, n));
}
END_TEST

Suite *suite_memcmp(void) {
  Suite *s = suite_create("suite_memcmp");
  TCase *tc = tcase_create("memcmp_tc");

  tcase_add_test(tc, similar_strings);
  tcase_add_test(tc, similar_array);
  tcase_add_test(tc, zero_n);
  tcase_add_test(tc, empty);
  tcase_add_test(tc, strings);
  tcase_add_test(tc, array);

  suite_add_tcase(s, tc);

  return s;
}
