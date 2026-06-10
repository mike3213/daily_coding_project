#include<iostream>
using namespace std;
int main(void){
	unsigned int n = 0;
	cin >> n;
	unsigned int map[100001] = {0};
	for(int i = 0; i < n; ++i){
		unsigned int temp = 0;
		cin >> temp;
		map[temp] += 1;
	}
	unsigned long long dp[3] = {0};
	for(unsigned long long i = 1; i <= 100000; ++i){
		if(map[i] != 0){
			dp[2] =	dp[0] + map[i] * i  > dp[1] ? dp[0] + map[i] * i : dp[1];
			dp[0] = dp[1], dp[1] = dp[2];
		} else {
			dp[2] = dp[1];
			dp[0] = dp[1], dp[1] = dp[2];
		}
	}
	
	cout << dp[1];

	return 0;
}
