#include "../../src/2024/2024.h"
#include "../common/assert.h"


void test_2024_01_a_case_1(){
    int left[] = {3, 4, 2, 1, 3, 3};
    int right[] = {4, 3, 5, 3, 9, 3};
    int n = sizeof(left) / sizeof(left[0]);
    int distance = solve_2024_01_a(left, right, n);
    ASSERT_EQ(11, distance, "Distance should be 11");
}


void test_2024_01_a_case_2(){
    FILE *file = fopen("tests/2024/01_input.txt", "r");
    int n = 1000;
    int left[n];
    int right[n];
    for (int i = 0; i < n; i++){
        fscanf(file, "%d %d", &left[i], &right[i]);
    }
    fclose(file);

    int distance = solve_2024_01_a(left, right, n);
    printf("Distance: %d\n", distance);
}

void test_2024_01_b_case_1(){
    int left[] = {3, 4, 2, 1, 3, 3};
    int right[] = {4, 3, 5, 3, 9, 3};
    int n = sizeof(left) / sizeof(left[0]);
    int score = solve_2024_01_b(left, right, n);
    ASSERT_EQ(31, score, "Distance should be 31");
}

void test_2024_01_b_case_2(){
    FILE *file = fopen("tests/2024/01_input.txt", "r");
    int n = 1000;
    int left[n];
    int right[n];
    for (int i = 0; i < n; i++){
        fscanf(file, "%d %d", &left[i], &right[i]);
    }
    fclose(file);

    int score = solve_2024_01_b(left, right, n);
    printf("Distance: %d\n", score);
}


int main(){
    test_2024_01_a_case_1();
    test_2024_01_a_case_2();
    test_2024_01_b_case_1();
    test_2024_01_b_case_2();
}