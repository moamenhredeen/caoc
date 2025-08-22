#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../src/2024/2024.h"
#include "../common/assert.h"

#define MAX_BUF_SIZE 1024

void test_solve_2024_02_a_case_1() {
  int reports[30] = {
      7, 6, 4, 2, 1, 1, 2, 7, 8, 9, 9, 7, 6, 2, 1,
      1, 3, 2, 4, 5, 8, 6, 4, 4, 1, 1, 3, 6, 7, 9,
  };

  int reports_lengths[6] = {5, 5, 5, 5, 5, 5};

  int safe_reports = solve_2024_02_a(reports, reports_lengths, 6);
  ASSERT_EQ(2, safe_reports, "safe_reports should be 2");
}

void test_solve_2024_02_a_case_2() {
  FILE *file = fopen("tests/2024/02_input.txt", "r");
  if (file == NULL) {
    perror("could not open the file");
    exit(1);
  }

  int lines = 1000;
  int reports[1000 * MAX_BUF_SIZE];
  int reports_lengths[1000];

  size_t line_length = 100;
  size_t line_cap = 0;
  size_t current_line = 0;
  size_t index = 0;
  size_t length_index = 0;
  char buf[MAX_BUF_SIZE];

  while (fgets(buf, MAX_BUF_SIZE, file)){
    char *token;
    int i;
    for (token = strtok(buf, " "), i = 0; i < MAX_BUF_SIZE && token != NULL; token = strtok(NULL, " "), i++){
      reports[index++] =  atoi(token);
    }
    
    reports_lengths[length_index++] = i;
  }
  
  int safe_reports = solve_2024_02_a(reports, reports_lengths, 1000);
  printf("safe reports: %d\n", safe_reports);
  fclose(file);
}

int main() {
  test_solve_2024_02_a_case_1();
  test_solve_2024_02_a_case_2();
  return 0;
}