
#include <array>
#include <iostream>
#include <climits>
#include "sort/sort_algorithms.h"

using namespace std;

void MergeSort::Merge(int input[], int p, int q, int r) {
    int n1 = q - p + 1; // +1 because the q element will go into the left array
    int n2 = r - q;
    int* L = new int[n1 + 1];
    int* R = new int[n2 + 1];
    
    for (int i = 0; i < n1; i++) {
        L[i] = input[p + i];
    }
    
    for (int i = 0; i < n2; i++) {
        R[i] = input[q + 1 + i]; // +1 because the q element has already been processed (in the left array)
    }
    
    int i = 0;
    int j = 0;
    
    for (int k = p; k <= r; k++) {
        if ((L[i] <= R[j] && i < n1) || (j >= n2)) { // "i < n1" if the left has no more elements, "j >= n2" => if the right array has no more element
            input[k] = L[i];
            i = i + 1;
        } else {
            input[k] = R[j];
            j = j + 1;
        }
    }
    
}
    
void MergeSort::MergeSplit(int input[], int p, int r) {
    if (p < r) {
        int q = (p + r)/2;
        MergeSplit(input, p, q);
        MergeSplit(input, q + 1, r); // +1 because the element at q is processed with the left part
        Merge(input, p, q, r);
    }
}
    
void MergeSort::Sort(int input[], int size) {
    MergeSplit(input, 0, size - 1);
}