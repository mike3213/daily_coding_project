#include <iostream>
using namespace std;
int main() {
    int n = 0;
    cin >> n;
    while(n-- > 0) {
        int L1 = 0, R1 = 0, L2 = 0, R2 = 0;
        cin >> L1 >> R1 >> L2 >> R2;
        cout << L1 << ' ';
        if(L2 != L1)
            cout << L2;
        else if(R2 != L1)
            cout << R2;




        if(n != 0)
                cout << '\n';
    }

    return 0;
}