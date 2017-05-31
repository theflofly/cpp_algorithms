#include <iostream>
#include <array>
#include "sort/sort_algorithms.h"
#include "questions/questions.h"

using namespace std;

int main(int argc, char** argv) {

    int menu = 1;
    int subMenu = 5;

    cout << "1 - Sorting algorithm" << endl;
    cout << "2 - Interview question" << endl;

    cin >> menu;

    switch(menu) {
        case 1:
            cout << "0 - Benchmark" << endl;
            cout << "1 - Insertion sort" << endl;
            cout << "2 - Merge sort" << endl;
            cout << "3 - Bubble sort" << endl;
            cout << "4 - Fastbit radix sort" << endl;
            cout << "5 - American flag sort" << endl;
            break;
        case 2:
            cout << "1 - Find maximum sub array recursive" << endl;
            cout << "2 - Rotate a matrix by 90°" << endl;
            cout << "3 - Rotate a matrix by N loop" << endl;
            break;
    }

    cin >> subMenu;

    cout << "Selected: " << menu << " " << subMenu << endl;  

    int input[25] = { 9, 7, 5, 3, 1, 45, 4, 7, 1011, 21, 89, 45, 14, 56, 8, 3, 45, 65, 25, 74, 1, 23, 96, 25, 63};

    switch (menu) {
        case 1: {
            switch (subMenu) {
                case 0: {

                    int M = 200000000;
                    int *long_array = new int[M];
                    for ( int i = 0; i < M; ++i ) {
                        long_array[i] = (i*15354943) & 65535;
                    }

                    int t = time(0);

                    FastbitRadixSort fastbitRadixSort = FastbitRadixSort();
                    fastbitRadixSort.sort(long_array, M);

                    cout << "FastbitRadixSort: " << time(0) - t << endl;

                    delete [] long_array;
                }
                case 1: {
                    InsertionSort insertionSort = InsertionSort();
                    insertionSort.sort(input, 25);
                    break; 
                }
                case 2: {
                    MergeSort mergeSort = MergeSort();
                    mergeSort.sort(input, 25);
                    break; 
                }
                case 3: {
                    BubbleSort bubbleSort = BubbleSort();
                    bubbleSort.sort(input, 25);
                    break; 
                }
                case 4: {
                    FastbitRadixSort fastbitRadixSort = FastbitRadixSort();
                    fastbitRadixSort.sort(input, 25);
                    break;
                }
                case 5: {
                    AmericanFlagSort americanFlagSort = AmericanFlagSort();
                    americanFlagSort.sort(input, 25);
                    break;
                }
            }
            break; }
        case 2: {
            switch (subMenu) {
                case 1: {
                    FindMaximumSubArrayRecursive fmsr = FindMaximumSubArrayRecursive();
                    fmsr.process();
                    break; }
                case 2: {
                    RotateMatrix90 rotateMatrix90 = RotateMatrix90();
                    rotateMatrix90.process();
                    break;
                }
                case 3: {
                    RotateMatrixN rotateMatrixN = RotateMatrixN();
                    rotateMatrixN.process();
                    break;
                }
            }
            break; }
    }

    if (menu == 1) {
        for (int i = 0; i < 25; i++) {
            cout << input[i] << ", ";
        }
        cout << endl;
        // should be 1, 1, 3, 3, 4, 5, 7, 7, 8, 9, 14, 21, 23, 25, 25, 45, 45, 45, 56, 63, 65, 74, 89, 96, 1011
    }

    return 0;
}
          