#include<iostream>
using namespace std;
int main(void){
	unsigned int arr[3] = {0};
	cin >> arr[0] >> arr[1] >> arr[2];
	for(int i = 1; i < 3; ++i){
		int j = i - 1;
		int key = arr[i];
		while(j >= 0 && arr[j] > key){
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
	cout << arr[2] - arr[0];

	return 0;
}
