#include<iostream>
using namespace std;
int main(void){
	unsigned short problems = 0;
	cin >> problems;
	unsigned short result = 0;
	while(problems-- > 0){
		unsigned short a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		if(a + b + c >= 2){
			result += 1;
		}
	}

	cout << result;
	return 0;
}
