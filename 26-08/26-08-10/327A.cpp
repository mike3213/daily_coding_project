#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int n = 0;
    cin >> n;
    string str;
    for(int i = 0; i < n; ++i) {
        char ch = '\0';
        cin >> ch;
        if(ch != ' ')
            str.push_back(ch);
    }
    int total_ones = 0;
    for(int i = 0; i < n; ++i) {
        if(str[i] == '1')
            total_ones++;
    }
    int cur = 0, max_gain = -1e9;
    for(int i = 0; i < n; ++i) {
        int gain = str[i] == '0' ? 1 : -1;
        cur = cur > 0 ? cur + gain : gain;
        if(cur > max_gain)
            max_gain = cur;
    }
    cout << total_ones + max_gain;

    return 0;
}