#include <iostream>
using namespace std;
int main() {
    int n = 0, k = 0;
    cin >> n >> k;

    int primeFactors[20] = {0}, index = 0;
    
    int temp = n;
    while(temp % 2 == 0){
        primeFactors[index] = 2;
        index++;
        temp /= 2;
    }

    for(int i = 3; i * i <= n; i += 2){
        while(temp % i == 0) {
            primeFactors[index] = i;
            index++;
            temp /= i;
        }
    }
    if(temp > 1){
        primeFactors[index] = temp;
        index++;
    }

    if(index < k)
        cout << -1;
    else {
        for(int i = 0; i < k - 1; ++i){
            cout << primeFactors[i] << " ";
        }
        int mult = 1;
        for(int i = k - 1; i < index; ++i)
            mult *= primeFactors[i];
        cout << mult;
    } 

    return 0;
}