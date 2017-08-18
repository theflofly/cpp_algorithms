
#include<iostream>
#include<cstring>
#include <bitset>

using namespace std;

int main() {
    
    char str[] = "abcdeefg";
    int checker = 0;
    for (int i = 0; i < 8; i++) {
        int val = str[i] - 'a';
        if ((checker & (1 << val)) > 0) {
            cout << "Is not unique" << endl;
            return 0;
        }
        checker |= (1 << val);
    } 

    cout << "Is unique" << endl;

    return 0;
    
}
