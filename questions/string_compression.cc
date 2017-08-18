#include<iostream>

using namespace std;

int main() {

    string input = "aabcccccaaa";
    string result = "";
    int count = 0;

    for (int i = 0; i < input.length(); i++) {

        count++;
        if (i == (input.length() - 1) || input.at(i) != input.at(i + 1)) {
            result += input.at(i) + to_string(count);
            count = 0;
        }

    }

    cout << result << endl;

    return 0;
}