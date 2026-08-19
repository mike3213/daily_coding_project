#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0;
        cin >> n;
        vector<int> gangs(n, 0);
        int first = -1, second = -1;
        for(int i = 0; i < n; ++i) {
            cin >> gangs[i];
            if(first == -1)
                first = i;
            else if(second == -1 && gangs[i] != gangs[first])
                second = i;
        }
        if(second == -1)
            cout << "NO";
        else {
            cout << "YES" << '\n';
            vector<pair<int, int>> ans;
            ans.emplace_back(first + 1, second + 1);
            for(int i = 0; i < n; ++i) {
                if(i == first || i == second)
                    continue;
                if(gangs[i] != gangs[first])
                    ans.emplace_back(first + 1, i + 1);
                else if(gangs[i] != gangs[second])  
                    ans.emplace_back(second + 1, i + 1);
            }
            for(int i = 0; i < ans.size(); ++i) {
                cout << ans[i].first << ' ' << ans[i].second;
                if(i != ans.size() - 1)
                    cout << '\n';
            }
        }
        


        if(cases > 0)
            cout << '\n';
    }


    return 0;
}