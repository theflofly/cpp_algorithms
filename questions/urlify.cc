#include<iostream>

using namespace std;

int main() {

    string input = "Mr Jonh Smith    ";
    int length = 13;
    int idx = 13 + 3;

    for (int i = length - 1; i >= 0; i--) {
        if (input.at(i) == ' ') {
            input.at(idx--) = '0';
            input.at(idx--) = '2';
            input.at(idx--) = '%';
        } else {
            input.at(idx--) = input.at(i);
        }
        cout << input << endl;
    }

    cout << input << endl;
}