#include<iostream>
using namespace std;
int main(void){
	unsigned short n = 0, answer = 0;
	cin >> n;
	char current = '?';
	for(int i = 0; i < n; ++i){
		char temp = '\0';
		cin >> temp;
		if(temp == current){
			answer++;
		} else {
			current = temp;
		}
	}
	cout << answer;

	return 0;
}
