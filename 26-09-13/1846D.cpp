#include <bits/stdc++.h>
using namespace std;
int main() {
	int cases = 0;
	cin >> cases;
	while(cases-- > 0) {
		int n = 0, d = 0, h = 0;
		cin >> n >> d >> h;
		double area = 1.0 * d * h / 2.0;
		vector<int> y(n, 0);
		for(int i = 0; i < n; ++i) {
			cin >> y[i];
		}
		double sum_areas = 1.0 * area * n;
		double overlap = 0;
		for(int i = 1; i < n; ++i) {
			if(y[i] < y[i - 1] + h) {
				long long diff = y[i - 1] + h - y[i];
				double ratio = 1.0 * diff / (1.0 * h);
				overlap += ratio * ratio * area;
			}
		}
		double ans = sum_areas - overlap;
		cout << fixed << setprecision(6) << ans;
		
		if(cases != 0)
			cout << '\n';
	}

	return 0;
}