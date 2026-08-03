#include <iostream>
#include <string>
using namespace std;

int find_position(const string &str) {
    char a = str.at(0);
    for(int i = 1; i < str.size(); ++i) {
        char b = str.at(i);
        if(a <= 'z' && a >= 'a' && b <= 'z' && b >= 'a' ||
           a <= '9' && a >= '0' && b <= '9' && b >= '0' ||
           a <= 'Z' && a >= 'A' && b <= 'Z' && b >= 'A' )
            return i;
    }

    return 1;
}

int main() {
    int n = 0;
    cin >> n;
    string str;
    for(int i = 0; i < n; ++i) {
        bool uppercase_existed = false, lowercase_existed = false, digit_existed = false;
        cin >> str;
        for(auto &x : str) {
            if(x <= '9' && x >= '0')
                digit_existed = true;
            else if(x <= 'Z' && x >= 'A')
                uppercase_existed = true;
            else if(x <= 'z' && x >= 'a')
                lowercase_existed = true;
        }

        int position = find_position(str);
        if(!digit_existed && uppercase_existed && lowercase_existed) {
            str.at(position) = '0';
        } else if(digit_existed && !uppercase_existed && lowercase_existed) {
            str.at(position) = 'A';
        } else if(digit_existed && uppercase_existed && !lowercase_existed) {
            str.at(position) = 'a';
        } else if(!digit_existed && !uppercase_existed && lowercase_existed) {
            str.at(0) = '0', str.at(1) = 'A';
        } else if(!digit_existed && uppercase_existed && !lowercase_existed) {
            str.at(0) = '0', str.at(1) = 'a';
        } else if(digit_existed && !uppercase_existed && !lowercase_existed) {
             str.at(0) = 'a', str.at(1) = 'A';
        }
        cout << str;

        if(i != n - 1)
            cout << '\n';
    }

    return 0;
}