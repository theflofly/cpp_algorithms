// Given a text txt[0..n-1] and a pattern pat[0..m-1], write a function 
// search(char pat[], char txt[]) that prints all occurrences of pat[] and 
// its permutations (or anagrams) in txt[]. You may assume that n > m. 
// Expected time complexity is O(n).

#include<iostream>
#include<cstring>
#define MAX 256

using namespace std;

int main() {
    char txt[] = "BACDGABCDA";
    char pat[] = "ABCD";

    int size_pat = strlen(pat), size_txt = strlen(txt);
    int count_error = 0;
    int count_pat[MAX] = {0}, count_txt[MAX] = {0};

    for (int i = 0; i < size_pat; i++) {
        count_pat[pat[i]]++;
    }

    // to avoid check in the next loop
    for (int i = 0; i < size_pat; i++) {
        count_txt[txt[i]]++;
        if (count_txt[txt[i]] > count_pat[txt[i]]) {
            count_error++;
        }
    }

    for (int i = size_pat; i < size_txt; i++) {
        if (count_error == 0) {
            cout << "Found at index: " << i - size_pat << endl;
        }
        // must be done at the beginning to handle the case where
        // a letter is added and produce an error and the same letter
        // also removed
        count_txt[txt[i]]++;

        // check if the letter produces an error
        if (count_txt[txt[i]] > count_pat[txt[i]]) {
            count_error++;
        }

        // check if the letter removed was producing an error
        // if yes decrease the error by one
        if (count_txt[txt[i - size_pat]] > count_pat[txt[i - size_pat]]) {
            count_error--;
        }

        count_txt[txt[i - size_pat]]--;
    }
    if (count_error == 0) {
        cout << "Found at index: " << size_txt - size_pat << endl;
    }

    return 0;
}
