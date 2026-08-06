#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n = 0;
    cin >> n;
    vector<int> rating(n, 0);
    for(int i = 0; i < n; ++i) {
        cin >> rating.at(i);
    }
    for(int i = 0; i < n; ++i) {
        int cnt = 0;
        for(int j = 0; j < n; ++j) {
            if(i != j){
                if(rating.at(i) < rating.at(j))
                    cnt++;
            }
        }
        cout << cnt + 1;
        if(i != n - 1)
            cout << ' ';
    }

    return 0;
}