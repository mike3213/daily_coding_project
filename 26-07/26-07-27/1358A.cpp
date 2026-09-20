#include <iostream>
using namespace std;

int main() {
    int times = 0;
    cin >> times;

    while(times-- > 0) {
        int n = 0, m = 0;
        cin >> n >> m;

        int sum_of_lanterns = 0;
        if((n * m) % 2 == 0)
            sum_of_lanterns = n * m / 2;
        else 
            sum_of_lanterns = n * m / 2 + 1;

        cout << sum_of_lanterns;
        if(times != 0)
            cout << endl;
    }


    return 0;
}