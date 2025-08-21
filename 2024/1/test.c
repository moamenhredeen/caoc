#include <stdio.h>
#include "solution.h"

int main(){
    int left[] = {3, 4, 2, 1, 3, 3};
    int right[] = {4, 3, 5, 3, 9, 3};
    int n = sizeof(left) / sizeof(left[0]);
    int distance = solve(left, right, n);
    printf("%d\n", distance);
    return 0;
}