#include<iostream>
using namespace std;
int main(void){
	unsigned int n = 0, b = 0, d = 0;
	cin >> n >> b >> d;
	unsigned int waste_cumulation = 0, empty_times = 0;
	for(int i = 0; i < n; ++i){
		unsigned int orange_size = 0;
		cin >> orange_size;
		if(orange_size > b)
			continue;
		else {
			waste_cumulation += orange_size;
			if(waste_cumulation > d){
				empty_times++;
				waste_cumulation = 0;
			}
		}
	}
	cout << empty_times;

	return 0;
}
