#include "tests_suitcases.h"

int main(void) {
  run_tests();
  return 0;
}
void run_testcase(Suite *testcase) {
  SRunner *sr = srunner_create(testcase);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);
}

void run_tests(void) {
  Suite *list_cases[] = {suite_strlen(),   suite_strncmp(),  suite_memchr(),
                         suite_memcmp(),   suite_memcpy(),   suite_memset(),
                         suite_strncpy(),  suite_strcspn(),  suite_strpbrk(),
                         suite_strrchr(),  suite_strstr(),   suite_strtok(),
                         suite_strchr(),   suite_strncat(),  suite_strerror(),
                         suite_to_upper(), suite_to_lower(), suite_to_insert(),
                         suite_trim(),     suite_sprintf(),  S21_NULL};

  for (Suite **current_testcase = list_cases; *current_testcase != S21_NULL;
       current_testcase++) {
    run_testcase(*current_testcase);
  }
}
