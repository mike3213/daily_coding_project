#include <iostream>
using namespace std;
int main(){
    int n  = 0, b = 0, p = 0;
    cin >> n >> b >> p;

    int k = n, round = 0;
    while(k > 1){
        int temp = k;
        k /= 2;
        round += k;
        if(temp % 2 == 1)
            k++;
    }
    
    int x = 0, y = 0;
    x = round * (b * 2 + 1);
    y = p * n;

    cout << x << " " << y;

    return 0;
}