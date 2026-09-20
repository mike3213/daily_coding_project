#include<iostream>
using namespace std;
int main(void){
	unsigned short n = 0;
	cin >> n;
	int least = 0, most = 0;
	unsigned short amazing = 0;
	cin >> least;
	most = least;
	for(int i = 1; i < n; ++i){
		unsigned short temp = 0;
		cin >> temp;
		if(temp < least){
			amazing++;
			least = temp;
		} else if(temp > most){
			amazing++;
			most = temp;
		}
		
	}
	
	cout << amazing;

	return 0;
}
