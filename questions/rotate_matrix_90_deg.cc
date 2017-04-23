// this algorithm takes as input a square matrix and rotate it of 90°
// the input is a square matrix of size N

// the values are rotated as follow

// [4] 8 12 [16]
// 3 7 11 15
// 2 6 10 14
// [1] 5 9 [13]

// 4 [8] 12 16
// 3 7 11 [15]
// [2] 6 10 14
// 1 5 [9] 13

// 4 8 [12] 16
// [3] 7 11 15
// 2 6 10 [14]
// 1 [5] 9 13

// 1 2 3 4
// 5 [6] [7] 8
// 9 [10] [11] 12
// 13 14 15 16

// I advise to write the index of the elements that will be switched during one iteration
// and play with i, j and N to construct the correct indexes

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
            input[i][j] = i * N + j + 1;
        }
    }

    rotateMatrix(input, N);
    
}

void RotateMatrix::rotateMatrix(int **input, size_t N) {
    
    cout << "Input matrix" << endl;
    printMatrix(input, N);

    for (size_t i = 0; i < N/2; i++) {
        for (size_t j = i; j < N - i - 1; j++) {
            
            int buffer = input[i][j];

            input[i][j] = input[j][N - i - 1];
            input[j][N - i - 1] = input[N - i - 1][N - j - 1];
            input[N - i - 1][N - j - 1] = input[N - 1 - j][i];
            input[N - 1 - j][i] = buffer;
        }
    }

    printMatrix(input, N);

}

void RotateMatrix::printMatrix(int **input, size_t N) {

    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            cout << input[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

}