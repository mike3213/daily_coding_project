#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n = 0;
    cin >> n;
    vector<int> cities(n, 0);
    int min = 2 * 1e9;
    for(auto &x : cities) {
        cin >> x;
        if(x < min)
            min = x;
    }
    vector<int> index;
    for(int i = 0; i < cities.size(); ++i) {
        if(cities.at(i) == min) {
            index.emplace_back(i);
        }
    }
    if(index.size() == 1)
        cout << index.at(0) + 1;
    else
        cout << "Still Rozdil";

    return 0;
}