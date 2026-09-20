#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<unsigned int> map(1001, 0);
    for(int i = 0; i < n; ++i) {
        int t = 0;
        cin >> t;
        map[t]++;
    }

    //three numbers is not same each other; the diff of any two number is 1 or 2
    //choose three numbers from list of vector size
    bool is_existed = false;
    for(int i = 0; i < 999; ++i) {
        if(map[i] != 0 && map[i + 1] != 0 && map[i + 2] != 0) {
            is_existed = true;
        }
    }

    if(is_existed)
        cout << "YES";
    else
        cout << "NO";
    
    return 0;
}