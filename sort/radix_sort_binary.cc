
#include <iostream>
#include <bitset>
#include "sort/sort_algorithms.h"

using namespace std;

void RadixSortBinary::sort(int input[], int size) {
    
    for (int i = 0; i < size; i++) {
        string binary = bitset<8>(input[i]).to_string();
        cout << binary << endl;
    }
    
}