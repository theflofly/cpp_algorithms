#include<iostream>

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

void NullifyRow(int **input, size_t N, int r) {
    for (size_t i = 0; i <= N; i++) {
        input[r][i] = 0;
    }
}

void NullifyColumn(int **input, size_t N, int c) {
    for (size_t i = 0; i <= N; i++) {
        input[i][c] = 0;
    }
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

    // put some element at 0
    input[1][1] = 0;
    input[0][3] = 0;

    N = N - 1;
    PrintMatrix(input, N);

    bool rowHasZero = false;
    bool columHasZero = false;

    for (int i = 0; i <= N; i++) {
        if (input[0][i] == 0) {
            rowHasZero = true;
        }
        if (input[i][0] == 0) {
            columHasZero = true;
        }
    }

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            if (input[r][c] == 0) {
                input[r][0] = 0;
                input[0][c] = 0;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (input[i][0] == 0) {
            NullifyRow(input, N, i);
        }
    }

    for (int i = 1; i <= N; i++) {
        if (input[0][i] == 0) {
            NullifyColumn(input, N, i);
        }
    }

    if (rowHasZero) {
        NullifyRow(input, N, 0);
    }

    if (columHasZero) {
        NullifyColumn(input, N, 0);
    }

    PrintMatrix(input, N);

    return 0;
}