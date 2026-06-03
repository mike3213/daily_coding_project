#include<iostream>
#include<string>
using namespace std;
int main(void){
	int n = 0;
	cin >> n;
	string str = "";
	for(int i = 0; i < n; ++i){
		cin >> str;
		unsigned short len = str.length();
		if(len > 10){
			char result[5] = "";
			result[0] = str[0];
			unsigned short mid_len = len - 2;
			unsigned short index = 1;
			while(mid_len > 0){
				result[index] = mid_len % 10 + '0';
				index++;
				mid_len / = 10;
			}
			result[index] = str[len - 1];
			cout << result;
		} else{
			cout << str;
		}

	}
	
	return 0;
}
