#include <iostream>
using namespace std;

int main() {
    int n = 0;
    cin >> n;

    int cellsNum = 1;
    int stairNum = 0;
    for(int i = 2; i <= n; ++i) {
        cellsNum += stairNum * 4 + 4;
        stairNum++;
    }

    cout << cellsNum;

    return 0;
}