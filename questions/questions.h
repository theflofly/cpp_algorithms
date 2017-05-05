#ifndef QUESTION_H
#define QUESTION_H

using namespace std;

class FindMaximumSubArrayRecursive {
    public:
        void process();
    private:
        array<int, 3> findMaximumSubarray(array<int, 16> A, int low, int high);
        array<int, 3> findMaxCrossingSubarray(array<int, 16> A, int low, int mid, int high);
        void printProcessPartArray(array<int, 16> A, int low, int high, string markerL, string markerR);
};

class RotateMatrix90 {
    public:
        void process();
    private:
        void rotateMatrix90(int **input, size_t N);
        void printMatrix(int **input, size_t N);
};

class RotateMatrixN {
    public:
        void process();
    private:
        void rotateMatrixK(int **input, size_t N, int k);
        void printMatrix(int **input, size_t N);
};

#endif