#include <iostream>
#include <string>
using namespace std;
int main() {
    string str1, str2;
    cin >> str1 >> str2;
    for(auto &x : str1) {
        if(x <= 'Z' && x >= 'A') {
            x += -'A' + 'a';
        }
    }
    for(auto &x : str2) {
        if(x <= 'Z' && x >= 'A') {
            x +=  -'A' + 'a';
        }
    }
    int i = 0;
    for(i = 0; i < str1.size() && i < str2.size(); ++i) {
        if(str1.at(i) > str2.at(i)) {
            cout << 1;
            return 0;
        } else if(str1.at(i) < str2.at(i)) {
            cout << -1;
            return 0;
        }
    }
    cout << 0;

    return 0;
}