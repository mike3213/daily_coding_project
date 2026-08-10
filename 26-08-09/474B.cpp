#include <iostream>
#include <vector>
using namespace std;
int main() {
    int piles = 0;
    cin >> piles;
    vector<int> a(piles, 0);
    int sum = 0;
    for(auto &x : a) {
        cin >> x;
        sum += x;
        x = sum;
    }
    int worms = 0;
    cin >> worms;
    while(worms-- > 0) {
        int label = 0;
        cin >> label;
        int left = 0, right = a.size(), mid = 0;
        while(left < right) {
            mid = left + (right - left) / 2;
            if(label == a[mid]) {
                cout << mid + 1;
                break;
            }
            else if(label < a[mid])
                right = mid;
            else {
                left = mid + 1;
            }
        }
        if(label != a[mid]) {
            cout << right + 1;
        }
        

        if(worms != 0)
            cout << '\n';
    }
    
    
    

    return 0;
}