// this algorithm takes as input a square matrix and rotate it of k element
// the input is a square matrix of size N

#include <array>
#include <iostream>
#include <climits>
#include "questions.h"

using namespace std;

void RotateMatrixN::Process() {

    // init the input array
    size_t N = 6;
    int **input = new int*[N];
    
    for (size_t i = 0; i < N; i++) {
        input[i] = new int[N];
        for (size_t j = 0; j < N; j++) {
            input[i][j] = i * N + j + 1;
        }
    }

    // rotate of 10 elements
    RotateN(input, N, 10);
    
}

void RotateMatrixN::RotateN(int **input, size_t N, int k) {
    
    cout << "Input matrix" << endl;
    PrintMatrix(input, N);

    int circleNumber = N/2;

    // we cut the matrix in circle
    for (int i = 0; i < circleNumber; i++) {

        int start = i;
        int end = N - i;
        int sizeRow = end - start;
        int sizeCircle = 2 * sizeRow + 2 * (sizeRow - 2);
        int *circle = new int[sizeCircle];
        int index = 0;
        

        /* We compute the new position rotated directly when completing the circle.
           We take the index + the number of element that we want to shift modulo the size of the circle.
           Example:

           We have a matrix:
           1, 2, 3
           4, 5, 6
           7, 8, 9

           The first circle (and the only one) is:
           1, 2, 3, 6, 9, 8, 7, 4

           When converting the matrix to a circle we chose to put the 1 at the first position in the circle (seems legit),
           but we can directly compute the rotated index.

           Let's say that we want 10 elements rotation.
           1 should be at index 0 without rotation, so we put it at index 10. But the circle has only 8 places, so we do a 10 % 8, the rotated position
           of the 1 will be at index 2.
           2 should be at index 1 without rotation, so we put it at index 11. But the circle has only 8 places, so we do a 11 % 8, the rotated position
           of the 2 will be at index 3.
           And so on...

           Then we convert back the circles to the matrix and we have our rotated matrix.
        */

        for (int j = start; j < end; j++)
            circle[(index++ + k) % sizeCircle] = input[start][j];
        
        for (int j = start + 1; j < end; j++)
            circle[(index++ + k) % sizeCircle] = input[j][end - 1];

        for (int j = end - 2; j >= start; j--)
            circle[(index++ + k) % sizeCircle] = input[end - 1][j];

        for (int j = end - 2; j > start; j--)
            circle[(index++ + k) % sizeCircle] = input[j][start];

        index = 0;

        // using the circle with updated position we recreate the matrix
        for (int j = start; j < end; j++)
            input[start][j] = circle[index++];
        
        for (int j = start + 1; j < end; j++)
            input[j][end - 1] = circle[index++];

        for (int j = end - 2; j >= start; j--)
            input[end - 1][j] = circle[index++];

        for (int j = end - 2; j > start; j--)
            input[j][start] = circle[index++];

    }

    PrintMatrix(input, N);

}

void RotateMatrixN::PrintMatrix(int **input, size_t N) {

    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            cout << input[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

}