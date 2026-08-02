#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main() {
    string str;
    cin >> str;
    vector<vector<int>> QA_cnt(2, vector<int>(str.size(), 0));
    int Q_cnt = 0, A_cnt = 0;
    for(int i = 0; i < str.size(); ++i) {
        QA_cnt.at(0).at(i) = Q_cnt;
        QA_cnt.at(1).at(i) = A_cnt;
        if(str.at(i) == 'Q') {
            Q_cnt++;
        } else if(str.at(i) == 'A') {
            A_cnt++;
        }
    }
    int ans = 0;
    for(int i = 0; i < str.size(); ++i) {
        if(str.at(i) == 'A') {
            int front = QA_cnt.at(0).at(i);
            int behind = QA_cnt.at(0).at(str.size() - 1) - front;
            if(str.at(str.size() - 1) == 'Q')
                behind++;
            ans += front * behind;
        }
    }

    cout << ans;
    
    return 0;
}