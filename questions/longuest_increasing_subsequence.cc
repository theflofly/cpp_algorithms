// https://en.wikipedia.org/wiki/Longest_increasing_subsequence

#include<iostream>
#include<vector>
#include <math.h> 

using namespace std;

int main() {
    vector<int> input{0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};

    // contains the predecessor of the end of a sequence when it had been added
    // to index_last_element_sequence
    vector<int> predecessor(input.size(), 0);

    // contains the index of the last element of each sequence
    // a sequence in the 6th position in this vector means it is of length 6
    vector<int> index_last_element_sequence(input.size() + 1, 0);

    int length = 0;

    for (size_t i = 0; i < input.size(); i++) {

        // binary search to find where we put our ith element in index_last_element_sequence
        int lo = 1;
        int hi = length;

        while (lo <= hi) {

            int mid = ceil((hi + lo) / 2);
            if (input[index_last_element_sequence[mid]] < input[i])
                lo = mid + 1;
            else
                hi = mid - 1;

        }

        int new_length = lo;

        // we save the predecessor of the element that we add to index_last_element_sequence
        predecessor[i] = index_last_element_sequence[new_length - 1];

        // put the element into index_last_element_sequence, will a new or update regarding the result of the binary search
        index_last_element_sequence[new_length] = i;

        if (new_length > length) {
            length = new_length;
        }
    }

    // construct the solution, beginning from the last element of the longest sequence
    // and going trough all the predecessors
    vector<int> solution(length, 0);
    int index_solution_element = index_last_element_sequence[length];
    for (int i = length - 1; i >= 0; --i) {
        solution[i] = input[index_solution_element];
        index_solution_element = predecessor[index_solution_element];
    }

    for (auto soluce: solution) {
        cout << soluce << " ";
    }

    cout << endl;
    cout << "Length of Longest Increasing Subsequence is " << length << endl;
    return 0;
}
