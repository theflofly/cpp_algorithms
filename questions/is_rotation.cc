#include<iostream>

using namespace std;

int main() {
    string s1 = "waterbottle";
    string s2 = "erbottlewat";

    if (s1.length() != s2.length()) {
        cout << "No" << endl;
        return 0;
    }

    if ((s1 + s1).find(s2) != string::npos) {
        cout << "Yes" << endl;
        return 0;
    }

    cout << "No" << endl;
    return 0;
}