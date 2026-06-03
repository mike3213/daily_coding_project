#include<iostream>
using namespace std;
int main(void){
	unsigned int x = 0, steps = 0;
	cin >> x;
	steps = x / 5;
	steps = steps * 5 == x ? steps : steps + 1;
	cout << steps;

	return 0;
}
