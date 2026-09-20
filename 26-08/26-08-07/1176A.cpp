#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int queries = 0;
    cin >> queries;
    for(int i = 0; i < queries; ++i) {
        long long num = 0;
        cin >> num;
        int cnt = 0;
        while(num > 1) {
            if(num % 2 == 0)
                num /= 2;
            else if(num % 3 == 0)
                num = num / 3 * 2;
            else if(num % 5 == 0)
                num = num / 5 * 4;
            else {
                cout << -1;
                break;
            }
            cnt++;
        }

        if(num == 1)
            cout << cnt; 
        if(i != queries - 1)
            cout << '\n';
    }

    return 0;
}