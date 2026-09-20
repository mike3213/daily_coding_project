#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n = 0;
    cin >> n;
    vector<int> num(n, 0);
    int odd_cnt = 0, even_cnt = 0;
    long long sum = 0;
    int min_odd = 2e9;
    for(int i = 0; i < n; ++i) {
        cin >> num.at(i);
        if(num.at(i) % 2 == 0)
            even_cnt++;
        else {
            odd_cnt++;
            if(num.at(i) < min_odd)
                min_odd = num.at(i);
        }
        sum += num.at(i);
    }
    if(odd_cnt % 2 != 0)
        sum -= min_odd;

    cout << sum;

    return 0;
}