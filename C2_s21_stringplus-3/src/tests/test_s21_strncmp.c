#include "tests_suitcases.h"

START_TEST(similar) {
  char *s1 = "Hello, world!";
  char *s2 = "Hello, world!";

  ck_assert_int_eq(strncmp(s1, s2, 100), s21_strncmp(s1, s2, 100));
}
END_TEST

START_TEST(s1_less) {
  char *s1 = "Hello, C!";
  char *s2 = "I am glad to see you, C!";

  ck_assert_int_eq(strncmp(s1, s2, 3), s21_strncmp(s1, s2, 3));
}
END_TEST

START_TEST(s2_less) {
  char *s1 = "I am glad to see you, C!";
  char *s2 = "Hello, C!";

  ck_assert_int_eq(strncmp(s1, s2, 3), s21_strncmp(s1, s2, 3));
}
END_TEST

START_TEST(zero_n) {
  char *s1 = "I am glad to see you, C!";
  char *s2 = "Hello, C!";

  ck_assert_int_eq(strncmp(s1, s2, 0), s21_strncmp(s1, s2, 0));
}
END_TEST

START_TEST(big_n) {
  char *s1 = "I am glad to see you, C!";
  char *s2 = "Hello, C!";

  ck_assert_int_eq(strncmp(s1, s2, 50), s21_strncmp(s1, s2, 50));
}
END_TEST

START_TEST(empty) {
  char *s1 = "";
  char *s2 = "Hello, C!";

  ck_assert_int_eq(strncmp(s1, s2, 1), s21_strncmp(s1, s2, 1));
}
END_TEST

Suite *suite_strncmp(void) {
  Suite *s = suite_create("suite_strncmp");
  TCase *tc = tcase_create("strncmp_tc");

  tcase_add_test(tc, similar);
  tcase_add_test(tc, s1_less);
  tcase_add_test(tc, s2_less);
  tcase_add_test(tc, zero_n);
  tcase_add_test(tc, big_n);
  tcase_add_test(tc, empty);

  suite_add_tcase(s, tc);

  return s;
}
