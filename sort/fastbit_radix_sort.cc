
// fastbit recursive msd binary radix sort
// implementation of: https://www.researchgate.net/publication/312572736_Fastbit-radix_sort_Optimized_version_of_radix_sort
// 2 millions random integer => 22 sec

#include <iostream>
#include <bitset>
#include <climits>
#include "sort/sort_algorithms.h"

using namespace std;

void FastbitRadixSort::Sort(int input[], int size) {
    
    BinarySplit(input, input + size - 1, 1 << 16);

}

void FastbitRadixSort::BinarySplit(int *inputStart, int *inputEnd, int maxMask) {

    if (maxMask == 0) return;

    int *start = inputStart;
    int *end = inputEnd;

    while (start <= end) {
        if ((*start & maxMask) < (*end & maxMask)) {
            start++;
            end--;
        } else if ((*start & maxMask) > (*end & maxMask)) {
            swap(*start, *end);
            start++;
            end--;
        } else {
            if ((*start & maxMask) == 0) {
                start++;
            } else {
                end--;
            }
        }
    }

    if (((start - 1) - inputStart) == 1) {
        if (*(start - 1) < *inputStart) {
            swap(*(start - 1), *inputStart);
        }
    } else if (((start - 1) - inputStart) > 1) {
        BinarySplit(inputStart, start - 1, maxMask >> 1);
    }

    if (inputEnd - start == 1) {
        if (*start > *inputEnd) {
            swap(*inputEnd, *start);
        }
    } else if (inputEnd - start > 1) {
        BinarySplit(start, inputEnd, maxMask >> 1);
    }
}