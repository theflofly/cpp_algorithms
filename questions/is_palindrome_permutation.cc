#include<iostream>

using namespace std;

int main() {
    
    string input = "tact coa"; // permutation of taco cat
    
    int checker = 0;
    
    for (size_t i = 0; i < input.length(); i++) {
        int val = input.at(i) - 'a';
        int mask = 1 << val;
        if (val < 0) continue;
        if ((checker & mask) == 0) {
            checker |= mask;
        } else {
            checker &= ~mask;
        }
    }
    
    cout << checker << endl;
    
    cout << "Permutation of a palindrome? " << ((checker & (checker - 1)) == 0 ? "Yes" : "No") << endl;
    
}