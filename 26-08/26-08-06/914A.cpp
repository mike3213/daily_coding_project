#include <iostream>
#include <vector>
#include <string>
using namespace std;

int int_sqrt(int a) {
    //x1 = 1/2(x0 + a/x0)
    if(a < 0)
        return -1;
    if(a == 0)
        return 0;
    int x0 = a;
    while(true) {
        int x1 = (x0 + a / x0) / 2;
        if(x1 >= x0) 
            break;
        x0 = x1;
    }
    return x0;
}

int main() {
    int n = 0;
    cin >> n;
    vector<int> num(n, 0);
    int max = -1e7;
    for(int i = 0; i < n; ++i) {
        cin >> num.at(i);
        int t = int_sqrt(num.at(i));
        if(!(t * t == num.at(i)) && num.at(i) > max)
            max = num.at(i);
    }
    cout << max;

    return 0;
}