#include <iostream>
using namespace std;
int main() {
    int n = 0;
    cin >> n;
    int participants[100] = {0};
    for(int i = 0; i < n; ++i) {
        cin >> participants[i];
    }

    for(int i = 1; i < n; ++i) {
        int t = participants[i];
        int j = i;
        while(j > 0 && participants[j - 1] > t) {
            participants[j] = participants[j - 1];
            j--;
        }
        participants[j] = t;
    }

    int ways = 1;
    for(int i = 0; i < n - 1; ++i) {
        if(participants[i] == 0)
            continue;
        if(participants[i] != participants[i + 1])
            ways++;
    }

    cout << ways;

    return 0;
}