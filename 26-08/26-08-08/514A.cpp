#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    string num;
    cin >> num;

    for(int i = 0; i < num.size(); ++i) {
        if(i == 0 && num.at(i) == '9')
            continue;
        else if(num.at(i) > '4') {
            num.at(i) = '9' - num.at(i) + '0';
        }
    }
    long long res = 0;
    for(auto &x : num) {
        res = res * 10 + x - '0';
    }
    cout << res;

    return 0;
}