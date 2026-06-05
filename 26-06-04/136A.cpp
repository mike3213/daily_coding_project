#include<iostream>
using namespace std;
int main(void){
	unsigned short presentsOf[100] = {0};
	unsigned short n = 0;
	cin >> n;
	for(int i = 0; i < n; ++i){
		unsigned short temp = 0;
		cin >> temp;
		presentsOf[temp] = i + 1;
	}
	for(int i = 0; i < n; ++i){
		cout << presentsOf[i + 1];
		if(i != n - 1)
			cout << ' ';
	}
	return 0;
}
