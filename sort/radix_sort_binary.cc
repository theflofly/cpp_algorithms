
#include <iostream>
#include <bitset>
#include <climits>
#include "sort/sort_algorithms.h"

using namespace std;

void RadixSortBinary::sort(int input[], int size) {
    
    binarySplit(input, input + size - 1, 1 << 9);

}

void RadixSortBinary::binarySplit(int *inputStart, int *inputEnd, int maxMask) {

    if (maxMask == 0) return;
    
    int size = inputEnd - inputStart + 1;

    //cout << "Size: " << size << endl;

    int *start = new int[size];
    int *end = start + size;
    int *startPtr = start;
    int *endPtr = end;

    if (size <= 1) return;

    for (int *ptr = inputStart; ptr <= inputEnd; ptr++) {
        if (*ptr & maxMask) {
            *(end--) = *ptr; // (1)
        } else {
            *(start++) = *ptr; // (2)
        }
    }

    for (const int *ptr = startPtr; ptr < start; ptr++) {
        *(inputStart++) = *ptr;
    }
    for (const int *ptr = end + 1; ptr <= endPtr; ptr++) {
        *(inputStart++) = *ptr;
    }

    inputStart -= size;
    maxMask >>= 1;

    binarySplit(inputStart, inputStart + (start - startPtr - 1), maxMask);
    binarySplit(inputStart + (start - startPtr - 1) + 1, inputEnd, maxMask);

}