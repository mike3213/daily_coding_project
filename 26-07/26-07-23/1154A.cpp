#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long input[4];
    for(int i = 0; i < 4; ++i)
        cin >> input[i];
    
    for(int i = 1; i < 4; ++i) {
        int j = i;
        int t = input[i];
        while(j > 0 && t < input[j - 1]) {
            input[j] = input[j - 1];
            --j;
        }
        input[j] = t;
    }
    
    cout << input[3] - input[2] << " "
         << input[3] - input[1] << " "
         << input[3] - input[0];

    return 0;
}