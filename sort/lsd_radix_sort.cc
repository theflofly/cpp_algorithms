// LSD radix sort
// 14 seconds for 200 millions 32 bits integer
// thanks to
// https://ece.uwaterloo.ca/~dwharder/aads/Algorithms/Sorting/Binary_radix_sort/src/Binary_radix_sort_pointer.h

// if we take for instance
// [101, 100, 111, 001], the binary version of [5, 4, 7, 1]
// the algorithm works as follow
// we go from left to right and we check the last bit
// if the bit == 0 we put the number at the beginning, else at the end
// we have four iterations, to do the check we are using a mask = 1 and we do:
// (number & mask)
// [ , , , ]
// 1: [ , , , 101]
// 2: [100, , , 101]
// 3: [100, , 111, 101]
// 4: [100, 001,| 111, 101]
// the pipe | is the pivot, it is the separation between the numbers ending with
// 0 and the numbers
// ending with the 1
// then we increment the mask from 1 bitwise to the left: mask <= 1, now our
// mask is 10 (binary)
// from the start to the pipe, we compare the numbers to the mask and put it at
// the beginning if (number & mask) == 0 else
// at the end if (number & mask) == 1
// we have [100, 001,| 111, 101]
// [ , , , ]
// 1: [100 , , , ]
// 2: [100, 001, , ]
// from the end to the pipe, we compare the numbers to the mask and put it at
// the beginning if (number & mask) == 0 else
// at the end if (number & mask) == 1
// 3: [100 , 001, 101, ]
// 2: [100, 001, 101,| 111]
// then we increment the mask from 1 bitwise to the left: mask <= 1, now our
// mask is 100 (binary)
// from the start to the pipe, we compare the numbers to the mask and put it at
// the beginning if (number & mask) == 0 else
// at the end if (number & mask) == 1
// we have [100, 001, 101,| 111]
// [ , , , ]
// 1: [ , , , 100]
// 2: [001, , , 100]
// 3: [001, , 101, 100]
// from the end to the pipe, we compare the numbers to the mask and put it at
// the beginning if (number & mask) == 0 else
// at the end if (number & mask) == 1
// 4: [001, |111, 101, 100]
// now we have two choices
// 1: we swap the element from the pivot to the end, in our case 111 will be
// swapped with 100 and we would have
// 5: [001, |100, 101, 111] our sorted array
// else we do a last iteration (the same as before)
// we increment the mask from 1 bitwise to the left: mask <= 1, now our mask is
// 1000 (binary)
// from the start to the pipe, we compare the numbers to the mask and put it at
// the beginning if (number & mask) == 0 else
// at the end if (number & mask) == 1, as our numbers have 3 bits maximum
// (number & mask) will always gives 0 and the pivot
// will be at the end after this iteration
// we have [001, |111, 101, 100]
// [ , , , ]
// 1: [001 , , , ]
// from the end to the pipe, we compare the numbers to the mask and put it at
// the beginning if (number & mask) == 0 else
// at the end if (number & mask) == 1, (number & mask) always gives 0
// 2: [001, 100, , ]
// 3: [001, 100, 101, ]
// 4: [001 , 100, 101, 111|] we have our sorted array

#include <iostream>
#include "sort/sort_algorithms.h"

using namespace std;

void LSDRadixSort::Sort(int input[], int size) {
  int mask = 1;
  int max_mask = 1 << 31;
  int* pivot;
  int* copy_input = new int[size];
  int* tail_0 = copy_input;
  int* tail_1 = copy_input + size - 1;

  for (int* input_ptr = input; input_ptr < input + size; ++input_ptr) {
    if (*input_ptr & mask) {
      *(tail_1--) = *input_ptr;
    } else {
      *(tail_0++) = *input_ptr;
    }
  }

  pivot = tail_0;

  while (true) {
    mask <<= 1;
    pivot = CopyInput(copy_input, copy_input + size - 1, pivot, input,
                      input + size - 1, mask);
    if (mask == max_mask) break;

    mask <<= 1;
    pivot = CopyInput(input, input + size - 1, pivot, copy_input,
                      copy_input + size - 1, mask);
    if (mask == max_mask) break;
  }

  for (int *ptr_start = pivot, *ptr_end = input + size; pivot < ptr_end;
       ++ptr_start, --ptr_end) {
    std::swap(ptr_start, ptr_end);
  }
}

int* LSDRadixSort::CopyInput(int* from_start, int* from_end, int* pivot,
                             int* to_start, int* to_end, int mask) {
  while (from_start < pivot) {
    if (*from_start & mask) {
      *(to_end--) = *from_start++;
    } else {
      *(to_start++) = *from_start++;
    }
  }

  while (from_end >= pivot) {
    if (*from_end & mask) {
      *(to_end--) = *from_end--;
    } else {
      *(to_start++) = *from_end--;
    }
  }

  return to_start;
}