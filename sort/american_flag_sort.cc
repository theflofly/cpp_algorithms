
// fastbit recursive msd binary radix sort
// implementation of: https://www.researchgate.net/publication/312572736_Fastbit-radix_sort_Optimized_version_of_radix_sort
// 2 millions random integer => 22 sec

#include <iostream>
#include <bitset>
#include <climits>
#include "sort/sort_algorithms.h"

using namespace std;

void AmericanFlagSort::sort(int input[], int size) {
    
    static const int kByteSize = 8;
    static const int kBucketSize = 1 << kByteSize;
    static const int kMask = (1 << kByteSize) - 1;
    
    int nb_bytes = sizeof(int);
    int last[kBucketSize + 1];
    int *last_ptr = last + 1;
    size_t count[kBucketSize] = {0};

    for (int *i = input; i < input + size; i++) {
        static const int kMSB = T(0x80) << ((sizeof(T) - 1) * 8);
        string binary = bitset<8>((nb_bytes * kByteSize)).to_string();
        cout << binary << endl;
        ++count[((x ^ kMSB) >> (kByteSize * nb_bytes)) & kMask];
    }

    for (int i = 0; i < kBucketSize; i++) {
        //cout << count
    }
}