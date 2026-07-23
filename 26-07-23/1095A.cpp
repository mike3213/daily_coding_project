#include <iostream>
using namespace std;
int main() {
    int n = 0;
    cin >> n;
    char cipher[56] = {'\0'};
    cin >> cipher;

    int index = 0;
    for(int i = 1; index < n; ++i) {
        index += i;
        cout << cipher[index - 1];
    }   

    return 0;
}