#include<iostream>
using namespace std;
int main(void){
	char ch = '';
	while(cin >> ch){
		if(ch == 'H' || ch == 'Q' || ch == '9'){
			cout << "YES";
			ch = static_cast<char>(32);
			break;
		}
	}
	if(ch != static_cast<char>(32))
		cout << "NO";

	return 0;
}
