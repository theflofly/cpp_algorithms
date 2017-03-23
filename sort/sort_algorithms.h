#include "sort/sort.h"

#ifndef SORT_ALGORITHMS_H
#define SORT_ALGORITHMS_H

using namespace std;

class MergeSort: public Sort {
    public:
        void sort(int input[], int size);
    private:
        void merge(int input[], int p, int q, int r);
        void mergeSort(int input[], int p, int r);
};
class InsertionSort: public Sort {
    public:
        void sort(int input[], int size);
};
class BubbleSort: public Sort {
    public:
        void sort(int input[], int size);
};

#endif