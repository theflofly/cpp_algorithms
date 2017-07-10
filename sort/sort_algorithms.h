#include "sort/sort.h"

#ifndef SORT_ALGORITHMS_H
#define SORT_ALGORITHMS_H

using namespace std;

class MergeSort: public SortingAlgorithm {
    public:
        void Sort(int input[], int size);
    private:
        void Merge(int input[], int p, int q, int r);
        void MergeSplit(int input[], int p, int r);
};

class InsertionSort: public SortingAlgorithm {
    public:
        void Sort(int input[], int size);
};

class BubbleSort: public SortingAlgorithm {
    public:
        void Sort(int input[], int size);
};

class FastbitRadixSort: public SortingAlgorithm {
    public:
        void Sort(int input[], int size);
    private:
        void BinarySplit(int *inputStart, int *inputEnd, int maxMask);
};

class AmericanFlagSort: public SortingAlgorithm {
    public:
        void Sort(int input[], int size);
    private:
        void BucketSort256(int *start, int *end, int nb_bytes);
        void InsertionSort(int *start, int *end);
};

class LSDRadixSort: public SortingAlgorithm {
    public:
        void Sort(int input[], int size);
    private:
        int* CopyInput(int *from_start, int *from_end, int* pivot, int *to_start, int* to_end, int mask);
};

#endif