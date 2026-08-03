#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int n = 0;
    cin >> n;
    string s;
    getline(cin, s);
    vector<char> str(n, '\0');
    for(int i = 0; i < n; ++i) {
        getline(cin, s);
        str.at(i) = s.at(0);
    }
    
    int x = 0;
    vector<vector<int>> cnt(2, vector<int>(26, 0));
    for(int i = 0; i < n; ++i) {
        char ch = str.at(i);
        int num_of_split1 = cnt.at(0).at(ch - 'a');
        int num_of_split2 = cnt.at(1).at(ch - 'a');
        if(num_of_split1 < num_of_split2) {
            cnt.at(0).at(ch - 'a')++;
        } else {
            cnt.at(1).at(ch - 'a')++;
        }
    }

    for(int i = 0; i < 26; ++i) {
        int t1 = cnt.at(0).at(i), t2 = cnt.at(1).at(i);
        x +=  t1 * (t1 - 1) / 2;
        x +=  t2 * (t2 - 1) / 2;
    }
    cout << x;

    return 0;
}