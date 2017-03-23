
#include <iostream>
#include <array>
#include "sort/sort_algorithms.h"

using namespace std;

void InsertionSort::sort(int input[], int size) {
    
    for (int i = 1; i < size; i++) {
        int key = input[i];
        int idx = i - 1;
        while (idx >= 0 && input[idx] > key) {
            input[idx + 1] = input[idx];
            idx = idx - 1;
        }
        input[idx + 1] = key;
    }
    
}