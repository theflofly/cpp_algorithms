#include<iostream>

using namespace std;

int main() {

    string input = "permutation";
    string permutation = "erpumatnoit";
    
    if (permutation.length() != input.length()) {
        cout << "No" << endl;
        return 0;
    }

    int *letter = new int[26];

    for (int i = 0; i < input.length(); i++) {
        letter[input.at(i) - 'a']++;
    }

    for (int i = 0; i < permutation.length(); i++) {
        int char_number = permutation.at(i) - 'a';
        letter[char_number]--;
        if (letter[char_number] < 0) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}