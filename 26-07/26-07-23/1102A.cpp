#include <iostream>
#include<vector>
using namespace std;

int main() {
    long long n = 0;
    cin >> n;
    long long sum = (n + 1) * n / 2;
    
    int remainder = sum % 2;
    cout << remainder;
    return 0;
}