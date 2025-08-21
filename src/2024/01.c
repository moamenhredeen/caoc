#include <stdlib.h>

#include "2024.h"

int compare_int(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int solve_2024_01_a(int left[], int right[], int n){
    qsort(left, n, sizeof(int), compare_int);
    qsort(right, n, sizeof(int), compare_int);
    
    int distance = 0;
    for (int i = 0; i < n; i++){
        distance += abs(left[i] - right[i]);
    }
    return distance;
}


int solve_2024_01_b(int left[], int right[], int n){
    int score = 0;
    int count = 0;
    // TODO: instead of nested loop, which very inefficiant 
    // i should first count items of the right array
    // then retrieve the items count of left array
    // for that i need hash table
    for (int i = 0; i < n;  i++) {
        count = 0;
        for (int j = 0; j < n; j++){
            if (left[i] == right[j]) {
                count += 1;
            }
        }
        score += left[i] * count;
    }
    return score;
}