#include <iostream>
#include <string>
using namespace std;
int main() {
    int n = 0;
    cin >> n;
    string str;
    cin >> str;
    for(int i = 0; i < n - 1; ++i) {
        if(str.at(i) != str.at(i + 1)) {
            cout << "YES\n" << str.substr(i, 2);
            return 0;
        }
    }
    cout << "NO";

    return 0;
}