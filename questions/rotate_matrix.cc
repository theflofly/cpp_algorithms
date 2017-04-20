// this algorithm take as input a square matrix and rotate it of 90 elements
// the input is a square matrix of size n

#include <array>
#include <iostream>
#include <climits>
#include "questions.h"

using namespace std;

void RotateMatrix::process() {

    // init the input array
    size_t N = 4;
    int **input = new int*[N];
    
    for (size_t i = 0; i < N; i++) {
        input[i] = new int[N];
        for (size_t j = 0; j < N; j++) {
            input[i][j] = i * N + j;
        }
    }

    rotateMatrix(input, N);
    
}

void RotateMatrix::rotateMatrix(int **input, size_t N) {
    cout << N;
}