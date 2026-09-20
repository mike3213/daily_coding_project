#include<iostream>
using namespace std;
int main(void){
	long long num = 0;
	cin >> num;
	unsigned int times = 0;
	while(num > 0){
		unsigned int digit = num % 10;
		if(digit == 4 || digit == 7)
			times++;
		num /= 10;
	}
	if(times == 4 || times == 7)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}
