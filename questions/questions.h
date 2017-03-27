#ifndef QUESTION_H
#define QUESTION_H

using namespace std;

class FindMaximumSubArrayRecursive {
    public:
        void process();
    private:
        array<int, 3> find_maximum_subarray(array<int, 16> A, int low, int high);
        array<int, 3> find_max_crossing_subarray(array<int, 16> A, int low, int mid, int high);
        void printProcessPartArray(array<int, 16> A, int low, int high, string markerL, string markerR);
};

#endif