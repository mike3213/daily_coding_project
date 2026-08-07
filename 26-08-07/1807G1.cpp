#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n = 0;
    cin >> n;
    while(n-- > 0) {
        int size = 0;
        cin >> size;
        vector<int> arr(size, 0);
        for(int i = 0; i < size; ++i)
            cin >> arr.at(i);
        for(int i = 1; i < arr.size(); ++i) {
            int t = arr.at(i);
            int j = i;
            while(j > 0 && t < arr.at(j - 1)) {
                arr.at(j) = arr.at(j - 1);
                j--;
            }
            arr.at(j) = t;
        }
        if(arr.at(0) != 1) {
            cout << "NO" << '\n';
            continue;
        }
        long long sum = 1;
        for(int i = 1; i < arr.size(); ++i) {
            if(arr.at(i) <= sum) {
                sum += arr.at(i);
            } else {
                cout << "NO";
                sum = -1;
                break;
            }
        }
        if(sum != -1)
            cout << "YES";
        if(n != 0)
            cout << '\n';
    }

    return 0;
}