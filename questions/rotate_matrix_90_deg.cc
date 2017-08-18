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

using namespace std;

void PrintMatrix(int **input, size_t N) {

    for (size_t i = 0; i <= N; i++) {
        for (size_t j = 0; j <= N; j++) {
            cout << input[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

}

int main() {

    // init the input array
    size_t N = 4;
    int **input = new int*[N];
    
    for (size_t i = 0; i < N; i++) {
        input[i] = new int[N];
        for (size_t j = 0; j < N; j++) {
            input[i][j] = i * N + j + 1;
        }
    }

    N = N - 1;
    PrintMatrix(input, N);
    
    for (int num_circle = 0; num_circle < N/2 + 1; num_circle++) {

        for (int index_circle = num_circle; index_circle < N - num_circle; index_circle++) {

            int temp = input[num_circle][index_circle];
            input[num_circle][index_circle] = input[N - index_circle][num_circle];
            input[N - index_circle][num_circle] = input[N - num_circle][N - index_circle];
            input[N - num_circle][N - index_circle] = input[index_circle][N - num_circle];
            input[index_circle][N - num_circle] = temp;

        }

    }

    PrintMatrix(input, N);
}

