#include <iostream>
using namespace std;
int main() {
    int n = 0;
    cin >> n;
    while(n-- > 0) {
        int a = 0, b = 0, c = 0, d = 0;
        cin >> a >> b >> c >> d;
        int max = a > b ? a : b;
        if(max < c)
            max = c;
        int need_to_equal = max * 3 - a - b - c;
        int remainder = d - need_to_equal;
        if(remainder < 0)
            cout << "NO";
        else if(remainder == 0)
            cout << "YES";
        else {
            if(remainder % 3 == 0)
                cout << "YES";
            else
                cout << "NO";
        }
        if(n != 0)
            cout << '\n';
    }
    
    return 0;
}