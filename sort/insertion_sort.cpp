//
//  insertion_sort.cpp
//  cpp-algorithms
//
//  Created by Florian Courtial on 10/11/16.
//  Copyright © 2016 Florian Courtial. All rights reserved.
//

#include <iostream>
#include <array>

using namespace std;

class InsertionSort {
    
public:
    
    InsertionSort(){}
   
    void sort(int input[], int size) {
        
        for (int i = 1; i < size; i++) {
            int key = input[i];
            int idx = i - 1;
            while (idx >= 0 && input[idx] > key) {
                input[idx + 1] = input[idx];
                idx = idx - 1;
            }
            input[idx + 1] = key;
        }
        
    }
    
};