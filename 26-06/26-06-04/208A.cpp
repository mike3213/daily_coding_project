#include<iostream>
using namespace std;
int main(void){
	char str[201] = "";
	unsigned short len = 0;
	while(cin >> str[len++]);
	char result[201] = "";
	for(int i = 0; i < len; ++i){
		if(str[i] == 'W' && str[i + 1] == 'U' && str[i + 2] == 'B'){
			str[i] = str[i + 1] = str[i + 2] = '\0';
			i += 2;
		}
	}
	unsigned short j = 0;
	bool flag = false;
	for(int i = 0; i < len; ++i){
		while(str[i] != '\0'){
			result[j++] = str[i++];
			flag = true;
		}
		if(flag){
			result[j++] = ' ';
			flag = !flag;
		}
	}
	result[j] = '\0';

	cout << result;

	return 0;
}
