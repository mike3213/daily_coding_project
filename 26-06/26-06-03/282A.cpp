#include<iostream>
using namespace std;
int main(void){
	unsigned short n = 0;
	int value = 0;
	char statement[4] = "";
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> statement[0] >> statement[1] >> statement[2];
		if(statement[1] == '+')
			value++;
		else if (statement[1] == '-')
			value--;
	}

	cout << value;

	return 0;
}

