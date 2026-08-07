#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    string str;
    cin >> str;
    string res;
    for(int i = str.size() - 1; i >= 0; i -= 2) {
        int digit = (str.at(i) - '0')* 1;
        if(i - 1 >= 0)
            digit += (str.at(i - 1) - '0') * 2;
        res.push_back(char(digit + '0'));
    }
    int cnt = 0, cnt0 = 0;
    for(int i = 0; i < res.size(); ++i){
        if(res.at(i) == '1')
            cnt++;
        if(res.at(i) == '0')
            cnt0++;
    }
    if(cnt == 1 && cnt0 == res.size() - 1 || str == "0")
        cout << res.size() - 1;
    else
        cout << res.size();
    return 0;
}