#ifndef QUESTION_H
#define QUESTION_H

using namespace std;

class FindMaximumSubArrayRecursive {
    public:
        void Process();
    private:
        array<int, 3> FindMaximumSubarray(array<int, 16> A, int low, int high);
        array<int, 3> FindMaxCrossingSubarray(array<int, 16> A, int low, int mid, int high);
        void PrintProcessPartArray(array<int, 16> A, int low, int high, string markerL, string markerR);
};

class RotateMatrix90 {
    public:
        void Process();
    private:
        void Rotate90(int **input, size_t N);
        void PrintMatrix(int **input, size_t N);
};

class RotateMatrixN {
    public:
        void Process();
    private:
        void RotateN(int **input, size_t N, int k);
        void PrintMatrix(int **input, size_t N);
};

#endif