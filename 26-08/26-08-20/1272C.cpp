#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
int main() {
    int n = 0, k = 0;
    cin >> n >> k;
    vector<char> num(n, 0);
    unordered_map<char, bool> keyboard;
    keyboard.reserve(k);
    for(auto &x : num)
        cin >> x;
    for(int i = 0; i < k; ++i) {
        char ch = '\0';
        cin >> ch;       
        keyboard[ch] = true;
    }
    for(int i = 0; i < n; ++i) {
        if(keyboard.find(num[i]) != keyboard.end()) {
            num[i] = '$';
        }
    }
    long long ans = 0, cnt = 0;
    num.emplace_back('!');
    for(int i = 0; i < num.size(); ++i) {
        if(num[i] == '$')
            cnt++;
        else if(cnt > 0 || i == n - 1) {
            ans += (cnt + 1LL) * cnt / 2;
            cnt = 0;
        }
    }
    cout << ans;

    return 0;
}