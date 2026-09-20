#include<iostream>
using namespace std;
int main(void){
	unsigned int n = 0;
	cin >> n;
	char magnets[2] = "";
	char end = '\0';
	cin >> end >> end;
	unsigned groups = 1;
	for(int i = 1; i < n; ++i){
		cin >> magnets[0] >> magnets[1];
		if(magnets[0] == '1' && end == '1' || magnets[0] == '0' && end == '0')
			groups++;
		end = magnets[1];
	}
	cout << groups;

	return 0;
}
