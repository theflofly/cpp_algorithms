#include<iostream>

using namespace std;

int main() {
    string s1 = "issubstring";
    string s2 = "nsg";

    int m = 0, n = 0;
    while (m < s1.length()) {
        if (n == s2.length()) {
            break;
        }
        if (s1.at(m) == s2.at(n)) {
            m++;
            n++;
        } else {
            m++;
            n = 0;
        }
    }
    if (n == s2.length()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}