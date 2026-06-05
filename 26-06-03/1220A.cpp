#include<iostream>
using namespace std;
int main(void){
	int numOfn = 0, numOfz = 0;
	char in = '\0';
	while(cin >> in){
		if(in == 'n')
			numOfn++;
		else if(in == 'z')
			numOfz++;
	}
	/*
	long long sum = 0;
	for(int i = 0; i < numOfn + numOfz; ++i){
		if(i < numOfz)
			sum = sum * 2 + 0;
		else
			sum = sum * 2 + 1;
	}
	*/
	while(numOfn-- > 0)
		cout << '1' << ' ';
	while(numOfz-- > 0){
		cout << '0';
		if(numOfz != 0)
			cout << ' ';
	}

	return 0;
}
