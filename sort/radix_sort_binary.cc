
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

    int *start = inputStart;
    int *end = inputEnd;
    int *startPtr = start;
    int *endPtr = end;

    if (size <= 1) return;

    cout << "Mask " << bitset<10>(maxMask).to_string() << endl;

    while (start < end) {
        cout << "Start " << *start << " End " << *end;
        if ((*start & maxMask) < (*end & maxMask)) {
            start++;
            end--;
            cout << " - OK ";
        } else if ((*start & maxMask) > (*end & maxMask)) {
            cout << " - SWAP " << *start << " and " << *end << endl;
            swap(*start, *end);
            start++;
            end--;
        } else {
            if ((*start & maxMask) == 0) {
                cout << " end and start 0";
                start++;
            } else {
                end--;
                cout << " end and start 1";
            }
        }
        cout << endl;
    }

    for (int *ptr = inputStart; ptr <= inputEnd; ptr++) {
         string binary = bitset<10>(*ptr).to_string();
         cout << binary << " " << *ptr << endl;
    }


    cout << "Processing right part from " << *start << " to " << *(inputEnd) << endl;
    binarySplit(inputStart, start, maxMask >>= 1);
    cout << "Processing right part from " << *start << " to " << *(inputEnd) << endl;
    binarySplit(start, inputEnd, maxMask >>= 1);

}