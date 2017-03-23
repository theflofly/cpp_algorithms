
#include <array>
#include <iostream>
#include <climits>
#include "sort/sort_algorithms.h"

void BubbleSort::sort(int input[], int size) {
    
    // the smaller value is brought to the left part of the array during the (2) loop
    // the [0, i] array is sorted
    for (int i = 0; i < size; i++) { // (1)
        
        // beginning from the end, two by two the values are compared with a sliding window of 1
        // the effect is to bring to the beginning the smaller value encountered on the [size, i] path
        for (int j = size - 1; j > i; j--) { // (2)
            
            // two adjacent values are compared and the smaller one goes on the left
            if (input[j] < input[j - 1]) {
                int buff = input[j];
                input[j] = input[j - 1];
                input[j - 1] = buff;
            }
        }
    }
}