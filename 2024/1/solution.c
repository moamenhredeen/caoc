#include <stdlib.h>

int solve(int *left, int *right, int n){
    int distance = 0;
    for(int i = 0; i < n; i++){
        distance += abs(left[i] - right[i]);
    }
    return distance;
}
