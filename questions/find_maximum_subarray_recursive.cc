
// make a header file using a template for sort
// build using bazel

#include <array>
#include <iostream>
#include <climits>
#include "questions.h"

using namespace std;

void FindMaximumSubArrayRecursive::process() {

    array<int, 16> input = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15,-4, 7};
    array<int, 3> result = find_maximum_subarray(input, 0, 15);
    cout << "The maximum subarray begins at " << result[0] << ", ends at " << result[1] << " and its value is " << result[2] << endl;

}

// the result contains three numbers [low idx of the subarray, high idx of the subarray, total value of the subarray]
array<int, 3> FindMaximumSubArrayRecursive::find_maximum_subarray(array<int, 16> A, int low, int high) {

    cout << "low " << low << endl;
    cout << "high " << high << endl;
    if (low == high) {
        return {low, high, A[low]};
    } else {
        int mid = (low + high) / 2;
        cout << "Processing left between " << low << " " << mid << endl;
        array<int, 3> left_result = find_maximum_subarray(A, low, mid);
        cout << "Processing right between " << mid + 1 << " " << high << endl;
        array<int, 3> right_result = find_maximum_subarray(A, mid + 1, high);
        cout << "Processing crossing between " << low << " " << high << endl;
        array<int, 3> crossing_result = find_max_crossing_subarray(A, low, mid, high);

        cout << left_result[2] << " " << right_result[2] << " " << crossing_result[2] << endl;

        // we search which part has the best subarray
        if (left_result[2] >= right_result[3] || left_result[2] >= crossing_result[2]) {
            cout << "best result left " << left_result[2] << endl;
            return left_result;
        } else if (right_result[2] >= left_result[2] || right_result[2] >= crossing_result[2]) {
            cout << "best result right " << right_result[2] << endl;
            return right_result;
        } else {
            cout << "best result crossing " << crossing_result[2] << endl;
            return crossing_result;
        }
    }
}

array<int, 3> FindMaximumSubArrayRecursive::find_max_crossing_subarray(array<int, 16> A, int low, int mid, int high) {

    cout << "find_max_crossing_subarray(" << low << ", " << mid << ", " << high << ")" << endl;
    int left_sum = INT_MIN;
    int right_sum = INT_MIN;
    int sum = 0;
    int max_left;
    int max_right;

    for (int i = mid; i >= 0; i--) {
        sum += A[i]; 
        if (sum > left_sum) {
            left_sum = sum;
            max_left = i;
        }
        cout << "r " << sum << endl;
    }
    
    sum = 0;
    for (int i = mid + 1; i <= high; i ++) {
        sum += A[i];
        
        if (sum > right_sum) {
            right_sum = sum;
            max_right = i;
        }
        cout << "p " << sum << endl;
    }

    return {max_left, max_right, left_sum + right_sum};

}
