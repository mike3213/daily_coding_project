#include<iostream>
using namespace std;
int main(void){
	unsigned short numOfStus = 0, numOfPzls = 0;
	cin >> numOfStus >> numOfPzls;
	unsigned short puzzles[50] = {0};
	for(int i = 0; i < numOfPzls; ++i){
		cin >> puzzles[i];
	}
	for(int i = 1; i < numOfPzls; ++i){
		int j = i - 1;
		int key = puzzles[i];
		while(j >= 0 && puzzles[j] >  key){
			puzzles[j + 1] = puzzles[j];
			j--;
		}
		puzzles[j + 1] = key;
	}
	unsigned short min = 1000;
	for(int i = 0; i < numOfPzls - numOfStus + 1; ++i){
		if(puzzles[i + numOfStus - 1] - puzzles[i] < min)
			min = puzzles[i + numOfStus - 1] - puzzles[i]; 
	}
	cout << min;

	return 0;
}
