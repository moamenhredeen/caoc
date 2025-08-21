#include "../../src/2024/2024.h"
#include "../common/assert.h"

int main(){
    int left[] = {3, 4, 2, 1, 3, 3};
    int right[] = {4, 3, 5, 3, 9, 3};
    int n = sizeof(left) / sizeof(left[0]);
    int distance = solve_2024_01_a(left, right, n);
    ASSERT_EQ(-11, distance, "Distance should be 11");
    return 0;
}