#include<iostream>
using namespace std;
int main(void){
	unsigned long long n = 0, k = 0;
	cin >> n >> k;
	unsigned long long num = n / 2;
	if(n % 2 != 0)
		num += 1;
	
	if(k <= num)
		cout << 2 * k - 1;
	else 
		cout << (k - num) * 2;
	return 0;
}
