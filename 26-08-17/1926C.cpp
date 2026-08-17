#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<long long> record(200001, 0);
    for(int i = 1; i < 200001; ++i) {
        int digit_sum = 0, x = i;
        while(x > 0) {
            int digit = x % 10;
            digit_sum += digit;
            x /= 10;
        }
        record[i] = record[i - 1] + digit_sum;
    }
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0;
        cin >> n;
        cout << record[n];

        if(cases > 0)
            cout << '\n';
    }

    return 0;
}