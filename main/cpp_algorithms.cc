#include <iostream>
#include <array>
#include "sort/sort_algorithms.h"
#include "questions/questions.h"

using namespace std;

int main(int argc, char** argv) {

    int menu;
    int subMenu;

    cout << "1 - Sorting algorithm" << endl;
    cout << "2 - Interview question" << endl;

    cin >> menu;

    switch(menu) {
        case 1:
            cout << "1 - Insertion sort" << endl;
            cout << "2 - Merge sort" << endl;
            cout << "3 - Bubble sort" << endl;
            break;
        case 2:
            cout << "1 - Find maximum sub array recursive" << endl;
            break;
    }

    cin >> subMenu;
    
    //int input[25] = { 9, 7, 5, 3, 1, 45, 4, 7, 1011, 21, 89, 45, 14, 56, 8, 3, 45, 65, 25, 74, 1, 23, 25, 96, 63};
    
    //InsertionSort insertionSort = InsertionSort();
    //insertionSort.sort(input, 25);
    
    //MergeSort mergeSort = MergeSort();
    //mergeSort.sort(input, 25);
    
    //BubbleSort bubbleSort = BubbleSort();
    //bubbleSort.sort(input, 25);
    
    //for (int i = 0; i < 25; i++) {
        //cout << input[i] << ", ";
    //}
    //cout << endl;
    
    // Make benchmark of the different sorting algorithms
    // Make a console software

    // should be 1, 1, 3, 3, 4, 5, 7, 7, 8, 9, 14, 21, 23, 25, 25, 45, 45, 45, 56, 63, 65, 74, 89, 96, 1011
    
    FindMaximumSubArrayRecursive fmsr = FindMaximumSubArrayRecursive();
    fmsr.process();

    return 0;
}
          