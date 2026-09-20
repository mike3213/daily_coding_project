#include<iostream>
using namespace std;
int main(void){
	unsigned short k = 0, w = 0;
	unsigned int n = 0;
	cin >> k >> n >> w;
	unsigned int sum = w * (w + 1) / 2 * k;
	if(n >= sum)
		cout << 0;
	else
		cout << sum - n;

	return 0;
}
