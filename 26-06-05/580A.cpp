#include<iostream>
#include<vector>
using namespace std;

int main(void){
	unsigned int n = 0;
	cin >> n;
	unsigned int money[100000];
	for(int i = 0; i < n; ++i){
		cin >> money[i];
	}
	unsigned int max = 1;
	for(int i = 0; i < n; ++i){
		if(n - 1 - i + 1 <= max)
			break;
		unsigned int current_len = 1;
		for(int j = i + 1; j < n; ++j){
			if(money[j] >= money[j - 1]){
				current_len++;
			} else {
				break;
			}
		}
		if(current_len > max)
			max = current_len;
	}
	cout << max;

	return 0;
}
