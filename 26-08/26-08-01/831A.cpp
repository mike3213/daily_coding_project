#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    if(n == 1)
        cout << "YES";
    else {
        int i = 1;
        int cur = 0, pre = 0;
        cin >> pre >> cur;
        while(i < n && cur > pre) {
            i++;
            if(i < n) {
                pre = cur;
                cin >> cur;
            }
        }
        while(i < n && cur == pre) {
            i++;
            if(i < n) {
                pre = cur;
                cin >> cur;
            }
        }
        while(i < n && cur < pre) {
            i++;
            if(i < n) {
                pre = cur;
                cin >> cur;
            }
        }
        if(i == n)
            cout << "YES";
        else
            cout << "NO";
    }

    return 0;
}