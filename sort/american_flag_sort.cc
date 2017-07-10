// american flag sort
// implementation of 2.2.3 in
// https://brage.bibsys.no/xmlui/bitstream/handle/11250/249906/124519_FULLTEXT01.pdf?sequence=1&isAllowed=y
// 2 millions random integer => 9 sec

#include <bitset>
#include <climits>
#include <iostream>
#include "sort/sort_algorithms.h"

using namespace std;

void AmericanFlagSort::Sort(int input[], int size) {
  BucketSort256(input, input + size, 3);
}

// from a number we have to find the bucket regarding the current byte
// the number is first shifted by the number of bytes so that the interesting
// byte is at the right
// then we apply the mask and we have a number between 0 and 255
// let's say we have a 32 bit unsigned integer: 3990433082
// its binary representation is 11101101110110010010110100111010
// we are beginning with the most significant byte, so nb_bytes = 3 (so that
// when shifting we keep the fourth byte) the first time we call BucketSort256,
// our mask is one byte, so 11111111. We shift our integer by 3 bytes to the
// right
// 11101101110110010010110100111010 >> 3 = 00000000000000000000000011101101
// we apply the mask
// 00000000000000000000000011101101 & 11111111 = 11101101 = 237
// for the first iteration our integer goes into the 237th bucket
// we recursively call BucketSort256 for each bucket reducing the nb_bytes by
// one <- IMPORTANT
// we sort the 237th bucket (because our integer is in this one) and nb_byte = 2
// we shift our integer by 2 bytes to the right
// 11101101110110010010110100111010 >> 2 = 00000000000000001110110111011001
// we apply the mask
// 00000000000000001110110111011001 & 11111111 = 11011001 = 217
// for the second iteration our integer goes into the 217th bucket
// and so on until we processed all the bytes (4 for an integer)
// (x >> (nb_bytes * 8)) & kMask; is duplicated three times because using a
// method gives worse performances
void AmericanFlagSort::BucketSort256(int *start, int *end, int nb_bytes) {
  static const int kBucketSize = 256;
  static const int kMask = 256 - 1;

  // last contains the beginning of each bucket from the input array (pointers)
  // really important, last points to 256 element from the input array
  // +1 because we will access last[-1] at some point
  // padded_last go from [-1, ..., 255]
  // last go from [0, 255]
  int *padded_last[kBucketSize + 1];
  int **last = padded_last + 1;
  int count[kBucketSize] = {0};

  // we count how many element there will be in each one of the 256 buckets
  for (int *i = start; i < end; i++) {
    ++count[(*i >> (nb_bytes * 8)) & kMask];
  }

  padded_last[0] = padded_last[1] = start;  // = last[-1] = last[0]
  // it means that last points to padded_last that points to the input array

  // we init the last array pointing to the beginning of each 256 bucket
  // in the input array
  for (int i = 1; i < kBucketSize; i++) {
    last[i] = last[i - 1] + count[i - 1];
  }

  // for each bucket
  for (int i = 0; i < 256; i++) {
    int *bucket_end = last[i - 1] + count[i];

    // there is only one bucket left, it should contains only correct elements
    // no need to go further
    if (bucket_end == end) {
      last[i] = end;
      break;
    }

    // while the end of the bucket is not reached
    while (last[i] != bucket_end) {
      int bucket = (*last[i] >> (nb_bytes * 8)) & kMask;

      // we swap until we reach our current bucket again
      if (bucket != i) {
        do {
          // we put the current element that we are processing at its right
          // place
          // and we increase by one the end of its bucket (because we just added
          // an element in the bucket)
          swap(*last[i], *last[bucket]++);
        
        // we compute the bucket of the element that we just swapped
        // because it is now our current element
        // if the element is okay for the current bucket i that we are
        // processing we stop
        } while ((bucket = (*last[i] >> (nb_bytes * 8)) & kMask) != i);  
      }
      ++last[i];  // we increment the position of the last element of the
                  // current bucket i
    }
  }

  if (nb_bytes > 0) {
    for (int i = 0; i < 256; i++) {
      if (count[i] < 64) {
        InsertionSort(last[i - 1], last[i]);
      } else if (count[i] > 0) {
        BucketSort256(last[i - 1], last[i], nb_bytes - 1);
      }
    }
  }
}

void AmericanFlagSort::InsertionSort(int *start, int *end) {
  for (int *i = start + 1; i < end; i++) {
    int *idx = i - 1;
    int key = *i;
    while (idx >= start && *idx > key) {
      *(idx + 1) = *idx;
      idx--;
    }
    *(idx + 1) = key;
  }
}