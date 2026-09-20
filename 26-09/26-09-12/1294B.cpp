#include <bits/stdc++.h>
using namespace std;
int main() {
	int cases = 0;
	cin >> cases;
	while(cases-- > 0) {
		int n = 0;
		cin >> n;
		vector<pair<int, int>> pos(n + 1, {0, 0});
		for(int i = 0; i < n; ++i) {
			cin >> pos[i].first >> pos[i].second;
		}
		sort(pos.begin(), pos.end());
		string ans;
		bool flag = true;
		for(int i = 1; i <= n; ++i) {
			if(pos[i].second < pos[i - 1].second) {
				flag = false;
				break;
			} else {
				ans.append(pos[i].first - pos[i - 1].first, 'R');
				ans.append(pos[i].second - pos[i - 1].second, 'U');
			}
		}
		if(!flag) {
			cout << "NO";
		} else {
			cout << "YES\n"
				 << ans;
		}
		
		if(cases != 0)
			cout << '\n';
	}

	return 0;
}