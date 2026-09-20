#include <iostream>
#include <vector>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int num = 0, k = 0;
        cin >> num >> k;
        if(num % 2 == 0 && k % 2 == 0) {
            //偶数个奇数或偶数
            int cnt1 = num / 1, cnt2 = num / 2;
            if(cnt1 < k && cnt2 < k)
                cout << "NO";
            else if(cnt1 >= k) {
                cout << "YES\n";
                for(int i = 0; i < k - 1; ++i)
                    cout << "1 ";
                cout << num - k + 1;
            } else if(cnt2 >= k) {
                cout << "YES\n";
                for(int i = 0; i < k - 1; ++i)
                    cout << "2 ";
                cout << num - 2 * k;
            }
        } else if(num % 2 == 0 && k % 2 != 0) {
            //奇数个偶数
            int cnt = num / 2;
            if(cnt < k)
                cout << "NO";
            else {
                cout << "YES\n";
                for(int i = 0; i < k - 1; ++i) {
                    cout << "2 ";
                }
                cout << num - 2 * (k - 1);
            }

        } else if(num % 2 != 0 && k % 2 == 0) {
            //不可能
            cout << "NO";
        } else {
            //奇数个奇数
            int cnt = num / 1;
            if(cnt < k)
                cout << "NO";
            else {
                cout << "YES\n";
                for(int i = 0; i < k - 1; ++i) {
                    cout << "1 ";
                }
                cout << num - k + 1;
            }
        }

        if(cases != 0)
            cout << '\n';
    }


    return 0;
}