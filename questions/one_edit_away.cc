#include<iostream>

using namespace std;

int main() {

    string first = "pale";
    string second = "bale";

    if (abs(static_cast<int>(first.length() - second.length())) > 1) {
        cout << "No" << endl;
        return 0;
    }

    int i1 = 0;
    int i2 = 0;
    bool found_difference = false;

    string s1 = first.length() < second.length() ? first : second;
    string s2 = first.length() < second.length() ? second : first;

    while (i1 < s1.length() && i2 < s2.length()) {
        if (s1.at(i1) != s2.at(i2)) {
            if (found_difference) {
                cout << "No" << endl;
                return 0;
            }
            found_difference = true;
            if (s1.length() == s2.length()) {
                i1++;
            }
        } else {
            i1++;
        }
        i2++;
    }

    cout << "Yes" << endl;

    return 0;
}