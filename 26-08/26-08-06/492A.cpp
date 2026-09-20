#include <iostream>
using namespace std;
int calc(int n) {
    return n * (n + 1) / 2;
}
int main() {
    int n = 0;
    cin >> n;
    int height = 0;
    while(n >= 0) {
        n -= calc(++height);
    }
    cout << height - 1;

    return 0;
}