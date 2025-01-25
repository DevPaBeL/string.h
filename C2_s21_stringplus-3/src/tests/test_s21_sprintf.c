#include "tests_suitcases.h"

START_TEST(int_d) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *format = "Hello, world number %d!";
  int value = 30;
  ck_assert_int_eq(s21_sprintf(s1, format, value), sprintf(s2, format, value));
  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(int_accuracy) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *format = "%.5d";
  int value = 3;
  ck_assert_int_eq(s21_sprintf(s1, format, value), sprintf(s2, format, value));
  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(float_99_minus) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *format = "%f";
  double value = -3.9999999;
  ck_assert_int_eq(s21_sprintf(s1, format, value), sprintf(s2, format, value));
  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(float_99) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *format = "%f";
  double value = 3.9999999;
  ck_assert_int_eq(s21_sprintf(s1, format, value), sprintf(s2, format, value));
  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(my_u) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *format = "%u";
  unsigned int value = -999;
  ck_assert_int_eq(s21_sprintf(s1, format, value), sprintf(s2, format, value));
  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(negative_int) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *format = "Negative number: %d";
  int value = -123;
  ck_assert_int_eq(s21_sprintf(s1, format, value), sprintf(s2, format, value));
  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(zero_int) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *format = "Zero: %d";
  int value = 0;
  ck_assert_int_eq(s21_sprintf(s1, format, value), sprintf(s2, format, value));
  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(char_value) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *format = "Character: %c";
  char value = 'A';
  ck_assert_int_eq(s21_sprintf(s1, format, value), sprintf(s2, format, value));
  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(char_newline) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *format = "Newline: %c";
  char value = '\n';
  ck_assert_int_eq(s21_sprintf(s1, format, value), sprintf(s2, format, value));
  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(positive_float) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *format = "Positive float: %f";
  double value = 123.456;
  ck_assert_int_eq(s21_sprintf(s1, format, value), sprintf(s2, format, value));
  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(negative_float) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *format = "Negative float: %f";
  double value = -123.456;
  ck_assert_int_eq(s21_sprintf(s1, format, value), sprintf(s2, format, value));
  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(small_float) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *format = "Small float: %f";
  double value = 0.000001;
  ck_assert_int_eq(s21_sprintf(s1, format, value), sprintf(s2, format, value));
  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(string_value) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *format = "String: %s";
  char *value = "Hello, World!";
  ck_assert_int_eq(s21_sprintf(s1, format, value), sprintf(s2, format, value));
  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(empty_string) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *format = "Empty string: %s";
  char *value = "";
  ck_assert_int_eq(s21_sprintf(s1, format, value), sprintf(s2, format, value));
  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(unsigned_int) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *format = "Unsigned int: %u";
  unsigned int value = 12345;
  ck_assert_int_eq(s21_sprintf(s1, format, value), sprintf(s2, format, value));
  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(zero_unsigned) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *format = "Unsigned zero: %u";
  unsigned int value = 0;
  ck_assert_int_eq(s21_sprintf(s1, format, value), sprintf(s2, format, value));
  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(length_h_int) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *format = "%hd";
  int value = 243242343;
  ck_assert_int_eq(s21_sprintf(s1, format, value), sprintf(s2, format, value));
  ck_assert_str_eq(s1, s2);
}

START_TEST(length_l_int) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *format = "%ld";
  long int value = 1234567890L;
  ck_assert_int_eq(s21_sprintf(s1, format, value), sprintf(s2, format, value));
  ck_assert_str_eq(s1, s2);
}

START_TEST(length_h_uint) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *format = "%hu";
  unsigned int value = 243242343;
  ck_assert_int_eq(s21_sprintf(s1, format, value), sprintf(s2, format, value));
  ck_assert_str_eq(s1, s2);
}

START_TEST(length_l_uint) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *format = "%lu";
  long unsigned int value = 2147483648UL;
  ck_assert_int_eq(s21_sprintf(s1, format, value), sprintf(s2, format, value));
  ck_assert_str_eq(s1, s2);
}

START_TEST(falgs_tests1d) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *format = "%+d";
  int value = 42542;
  ck_assert_int_eq(s21_sprintf(s1, format, value), sprintf(s2, format, value));
  ck_assert_str_eq(s1, s2);
}

START_TEST(falgs_tests2f) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *format = "%+f";
  double value = 575467.54321543;
  ck_assert_int_eq(s21_sprintf(s1, format, value), sprintf(s2, format, value));
  ck_assert_str_eq(s1, s2);
}

START_TEST(falgs_test_d) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *format = "% d";
  int value = 42542;
  ck_assert_int_eq(s21_sprintf(s1, format, value), sprintf(s2, format, value));
  ck_assert_str_eq(s1, s2);
}

START_TEST(falgs_test_f) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *format = "% f";
  double value = 575467.54321543;
  ck_assert_int_eq(s21_sprintf(s1, format, value), sprintf(s2, format, value));
  ck_assert_str_eq(s1, s2);
}

START_TEST(precision_with_zero__width_d1) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *format = "%-10.d";
  int value = 0;
  ck_assert_int_eq(s21_sprintf(s1, format, value), sprintf(s2, format, value));
  ck_assert_str_eq(s1, s2);
}

START_TEST(precision_with_zero__width_d2) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *format = "%-10.5d";
  int value = -321;
  ck_assert_int_eq(s21_sprintf(s1, format, value), sprintf(s2, format, value));
  ck_assert_str_eq(s1, s2);
}

START_TEST(sluchai_with__szero) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *format = "%-15.f";
  double value = -0.0;
  ck_assert_int_eq(s21_sprintf(s1, format, value), sprintf(s2, format, value));
  ck_assert_str_eq(s1, s2);
}

START_TEST(sluchai_with__0_szero) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *format = "%-15.0f";
  double value = -0.0;
  ck_assert_int_eq(s21_sprintf(s1, format, value), sprintf(s2, format, value));
  ck_assert_str_eq(s1, s2);
}

START_TEST(nf1) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *format = "% 5.5f";
  double value = 4234.567757;
  ck_assert_int_eq(s21_sprintf(s1, format, value), sprintf(s2, format, value));
  ck_assert_str_eq(s1, s2);
}

START_TEST(nf2) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *format = "%+5.5f";
  double value = 4234.567757;
  ck_assert_int_eq(s21_sprintf(s1, format, value), sprintf(s2, format, value));
  ck_assert_str_eq(s1, s2);
}

START_TEST(nd1) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *format = "%+12.9d";
  int value = 4234;
  ck_assert_int_eq(s21_sprintf(s1, format, value), sprintf(s2, format, value));
  ck_assert_str_eq(s1, s2);
}

START_TEST(nd2) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *format = "%+12.3d";
  int value = 42344353;
  ck_assert_int_eq(s21_sprintf(s1, format, value), sprintf(s2, format, value));
  ck_assert_str_eq(s1, s2);
}

START_TEST(i1) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *format = "%.d";
  int value = 0;
  ck_assert_int_eq(s21_sprintf(s1, format, value), sprintf(s2, format, value));
  ck_assert_str_eq(s1, s2);
}

START_TEST(i2) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *format = "%.0d";
  int value = 0;
  ck_assert_int_eq(s21_sprintf(s1, format, value), sprintf(s2, format, value));
  ck_assert_str_eq(s1, s2);
}

START_TEST(i3) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *format = "%.3s";
  char *value = "world";
  ck_assert_int_eq(s21_sprintf(s1, format, value), sprintf(s2, format, value));
  ck_assert_str_eq(s1, s2);
}

START_TEST(i4) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *format = "%.5u";
  unsigned int value = 413;
  ck_assert_int_eq(s21_sprintf(s1, format, value), sprintf(s2, format, value));
  ck_assert_str_eq(s1, s2);
}

START_TEST(i6) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *format = "%.u";
  unsigned int value = 0;
  ck_assert_int_eq(s21_sprintf(s1, format, value), sprintf(s2, format, value));
  ck_assert_str_eq(s1, s2);
}

START_TEST(i7) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *format = "%.0u";
  unsigned int value = 0;
  ck_assert_int_eq(s21_sprintf(s1, format, value), sprintf(s2, format, value));
  ck_assert_str_eq(s1, s2);
}

START_TEST(i8) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *format = "%.21d";
  int value = 1234;
  ck_assert_int_eq(s21_sprintf(s1, format, value), sprintf(s2, format, value));
  ck_assert_str_eq(s1, s2);
}

START_TEST(i9) {
  char s1[BUFFER];
  char s2[BUFFER];
  char *format = "%.0d";
  int value = 0;
  ck_assert_int_eq(s21_sprintf(s1, format, value), sprintf(s2, format, value));
  ck_assert_str_eq(s1, s2);
}

Suite *suite_sprintf(void) {
  Suite *s = suite_create("suite_sprintf");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, int_d);
  tcase_add_test(tc, int_accuracy);
  tcase_add_test(tc, float_99_minus);
  tcase_add_test(tc, float_99);
  tcase_add_test(tc, my_u);
  tcase_add_test(tc, negative_int);
  tcase_add_test(tc, zero_int);
  tcase_add_test(tc, char_value);
  tcase_add_test(tc, char_newline);
  tcase_add_test(tc, positive_float);
  tcase_add_test(tc, negative_float);
  tcase_add_test(tc, small_float);
  tcase_add_test(tc, string_value);
  tcase_add_test(tc, empty_string);
  tcase_add_test(tc, unsigned_int);
  tcase_add_test(tc, zero_unsigned);
  tcase_add_test(tc, length_h_int);
  tcase_add_test(tc, length_l_int);
  tcase_add_test(tc, length_h_uint);
  tcase_add_test(tc, length_l_uint);
  tcase_add_test(tc, falgs_tests1d);
  tcase_add_test(tc, falgs_tests2f);
  tcase_add_test(tc, falgs_test_d);
  tcase_add_test(tc, falgs_test_f);
  tcase_add_test(tc, precision_with_zero__width_d1);
  tcase_add_test(tc, precision_with_zero__width_d2);
  tcase_add_test(tc, sluchai_with__szero);
  tcase_add_test(tc, sluchai_with__0_szero);
  tcase_add_test(tc, nf1);
  tcase_add_test(tc, nf2);
  tcase_add_test(tc, nd1);
  tcase_add_test(tc, nd2);
  tcase_add_test(tc, i1);
  tcase_add_test(tc, i2);
  tcase_add_test(tc, i3);
  tcase_add_test(tc, i4);
  tcase_add_test(tc, i6);
  tcase_add_test(tc, i7);
  tcase_add_test(tc, i8);
  tcase_add_test(tc, i9);

  suite_add_tcase(s, tc);

  return s;
}
