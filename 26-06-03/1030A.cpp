#include<iostream>
using namespace std;
int main(void){
	unsigned short n = 0;
	cin >> n;
	unsigned short isEasy = 0;
	for(int i = 0; i < n; ++i){
		cin >> isEasy;
		if(isEasy == 1)
			break;
	}
	if(isEasy == 1)
		cout << "HARD";
	else
		cout << "EASY";
	return 0;
}
