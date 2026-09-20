#include <bits/stdc++.h>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int t1 = 0, t2 = 0, t3 = 0, t4 = 0;
        cin >> t1 >> t2 >> t3 >> t4;
        long long total_jokes = t1;
        if(t1 > 0) {
            int com_t2_t3 = min(t2, t3);
            long long num = com_t2_t3 * 2;
            total_jokes += num;
            t2 -= com_t2_t3, t3 -= com_t2_t3;
            int alice_mood = t1, bob_mood = t1;
            if(t2 == 0) {
                total_jokes += t4 + t3 > alice_mood ? alice_mood + 1 : t4 + t3;
            } else if(t3 == 0) {
                total_jokes += t2 + t4 > bob_mood ? bob_mood + 1 : t2 + t4;
            }
            cout << total_jokes;
        } else 
            cout << 1;

        if(cases > 0)
            cout << '\n';
    }

    return 0;
}