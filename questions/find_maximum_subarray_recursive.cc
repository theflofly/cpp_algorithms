// as we are using recursion, it can be hard to see what is happening
// at each step the part of the array being processed is displayed between [ ]
// once a maximum sub array as been found it is displayed between ( )
// as we are using recursion, the left part of the arrays are always processed first

#include <array>
#include <iostream>
#include <climits>
#include "questions.h"

using namespace std;

void FindMaximumSubArrayRecursive::Process() {

    array<int, 16> input = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15,-4, 7};
    array<int, 3> result = FindMaximumSubarray(input, 0, 15);
    cout << "The maximum subarray begins at " << result[0] << ", ends at " << result[1] << " and its value is " << result[2] << endl;

}

// the result contains three numbers [low idx of the subarray, high idx of the subarray, total value of the subarray]
array<int, 3> FindMaximumSubArrayRecursive::FindMaximumSubarray(array<int, 16> A, int low, int high) {

    PrintProcessPartArray(A, low, high, "[", "]");
    
    if (low == high) {
        return {{low, high, A[low]}};
    } else {
        int mid = (low + high) / 2;
        array<int, 3> left_result = FindMaximumSubarray(A, low, mid);
        array<int, 3> right_result = FindMaximumSubarray(A, mid + 1, high);
        array<int, 3> crossing_result = FindMaxCrossingSubarray(A, low, mid, high);

        // we search which part has the best subarray
        if (left_result[2] >= right_result[2] && left_result[2] >= crossing_result[2]) {
            PrintProcessPartArray(A, left_result[0], left_result[1], "(", ")");
            return left_result;
        } else if (right_result[2] >= left_result[2] && right_result[2] >= crossing_result[2]) {
            PrintProcessPartArray(A, right_result[0], right_result[1], "(", ")");
            return right_result;
        } else {
            PrintProcessPartArray(A, crossing_result[0], crossing_result[1], "(", ")");
            return crossing_result;
        }
    }
}

array<int, 3> FindMaximumSubArrayRecursive::FindMaxCrossingSubarray(array<int, 16> A, int low, int mid, int high) {

    PrintProcessPartArray(A, low, high, "[", "]");
    int left_sum = INT_MIN;
    int right_sum = INT_MIN;
    int sum = 0;
    int max_left;
    int max_right;

    for (int i = mid; i >= low; i--) {
        sum += A[i]; 
        if (sum > left_sum) {
            left_sum = sum;
            max_left = i;
        }
    }
    
    sum = 0;
    for (int i = mid + 1; i <= high; i ++) {
        sum += A[i];
        
        if (sum > right_sum) {
            right_sum = sum;
            max_right = i;
        }
    }

    return {{max_left, max_right, left_sum + right_sum}};

}

void FindMaximumSubArrayRecursive::PrintProcessPartArray(array<int, 16> A, int low, int high, string markerL, string markerR) {
    for (size_t i = 0; i < A.size(); i++) {
        if (i != 0) {
            cout << ", ";
        }
        if (i == (size_t)low) {
            cout << markerL;
        }
        cout << A[i]; 
        if (i == (size_t)high) {
            cout << markerR;
        }
    }
    cout << endl;
}