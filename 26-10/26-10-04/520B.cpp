#include <bits/stdc++.h>
using namespace std;
int solution(int target, int start) {
    if(start >= target)
        return start - target;
    int operations = 0;
    if(target % 2 != 0) {
        target++;
        operations++;
    }
    if(start < target / 2) {
        operations += solution(target / 2, start);
        operations++;
    } else {
        operations += (start - (target / 2) + 1);
    }
    return operations;
}

int main (void) {
    int n = 0, m = 0;
    cin >> n >> m;
    int operations = solution(m, n);

    cout << operations;
    return 0;
}