//
//  main.cpp
//  cpp-tuto
//
//  Created by Florian Courtial on 07/11/16.
//  Copyright © 2016 Florian Courtial. All rights reserved.
//

#include <iostream>
#include <array>
#include "sort/insertion_sort.cpp"
#include "sort/merge_sort.cpp"
#include "sort/bubble_sort.cpp"

int main(int argc, const char * argv[]) {
    
    int input[25] = { 9, 7, 5, 3, 1, 45, 4, 7, 1011, 21, 89, 45, 14, 56, 8, 3, 45, 65, 25, 74, 1, 23, 25, 96, 63};
    
    //InsertionSort insertionSort = InsertionSort();
    //insertionSort.sort(input, 25);
    
    //MergeSort mergeSort = MergeSort();
    //mergeSort.sort(input, 25);
    
    BubbleSort bubbleSort = BubbleSort();
    bubbleSort.sort(input, 25);
    
    for (int i = 0; i < 25; i++) {
        cout << input[i] << ", ";
    }
    cout << endl;
    
    // should be 1, 1, 3, 3, 4, 5, 7, 7, 8, 9, 14, 21, 23, 25, 25, 45, 45, 45, 56, 63, 65, 74, 89, 96, 1011
    
    return 0;
}
