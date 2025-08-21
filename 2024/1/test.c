#include "solution.h"
#include "../../utils/assert.h"

int main(){
    int left[] = {3, 4, 2, 1, 3, 3};
    int right[] = {4, 3, 5, 3, 9, 3};
    int n = sizeof(left) / sizeof(left[0]);
    int distance = solve(left, right, n);
    ASSERT_EQ(-11, distance, "Distance should be 11");
    return 0;
}