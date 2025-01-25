#include "tests_suitcases.h"

START_TEST(hello) {
  const char *s = "Hello, world!";

  ck_assert_ptr_eq(strchr(s, 'w'), s21_strchr(s, 'w'));
}
END_TEST

START_TEST(term_zero) {
  const char *s = "Hello, world!";

  ck_assert_ptr_eq(strchr(s, '\0'), s21_strchr(s, '\0'));
}
END_TEST

START_TEST(not_find) {
  const char *s = "Hello, world!";

  ck_assert_ptr_eq(strchr(s, 'i'), s21_strchr(s, 'i'));
}
END_TEST

START_TEST(numbers) {
  const char *s = "1234567896565699";

  ck_assert_ptr_eq(strchr(s, '9'), s21_strchr(s, '9'));
}
END_TEST

START_TEST(first) {
  const char *s = "go go go go go home";

  ck_assert_ptr_eq(strchr(s, 'o'), s21_strchr(s, 'o'));
}
END_TEST

Suite *suite_strchr(void) {
  Suite *s = suite_create("suite_strchr");
  TCase *tc = tcase_create("strchr_tc");

  tcase_add_test(tc, hello);
  tcase_add_test(tc, term_zero);
  tcase_add_test(tc, not_find);
  tcase_add_test(tc, numbers);
  tcase_add_test(tc, first);

  suite_add_tcase(s, tc);

  return s;
}
