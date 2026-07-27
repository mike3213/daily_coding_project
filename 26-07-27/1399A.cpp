#include <iostream>
using namespace std;

int main() {
    int times = 0;
    cin >> times;
    while(times-- > 0) {
        int n = 0;
        cin >> n;
        int cnt[101] = {0};
        for(int i = 0; i < n; ++i) {
            int temp = 0;
            cin >> temp;
            cnt[temp] = 1;
        }
        int count = 0;
        for(int i = 1; i < 100; ++i) {
            if(cnt[i] > 0 && cnt[i + 1] == 0)
                count++;
        }
        if(count == 0 && cnt[100] != 0  || count == 1 && cnt[100] == 0)
            cout << "YES";
        else
            cout << "NO";
        if(times != 0)
            cout << endl;
        
    }

    return 0;
}