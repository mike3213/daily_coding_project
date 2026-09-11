#include <bits/stdc++.h>
using namespace std;
int main() {
	int cases = 0;
	cin >> cases;
	while(cases-- > 0) {
		int n = 0;
		cin >> n;
		vector<int> odd_num, even_num;
		long long sum_odds = 0, sum_evens = 0;
		for(int i = 0; i < n; ++i) {
			int t = 0;
			cin >> t;
			if(t % 2 == 0) {
				even_num.emplace_back(t);
				sum_evens += t;
			} else {
				odd_num.emplace_back(t);
				sum_odds += t;
			}
		}
		long long res = 0;
		if(odd_num.size() == 0) {
			res = *max_element(even_num.begin(), even_num.end());
		} else if(even_num.size() == 0) {
            res = *max_element(odd_num.begin(), odd_num.end());
        } else
            res = sum_odds - odd_num.size() + sum_evens + 1;
		cout << res;
		
		if(cases != 0)
			cout << '\n';
	}

	return 0;
}