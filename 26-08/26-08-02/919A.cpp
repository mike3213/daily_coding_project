#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int n = 0, m = 0;
    cin >> n >> m;
    vector<double> prices(n, 0);
    double min = 10000;
    for(int i = 0; i < n; ++i) {
        int a = 0, b = 0;
        cin >> a >> b;
        prices.at(i) = a * 1.0 / b;
        if(prices.at(i) < min)
            min = prices.at(i);
    }

    cout << fixed << setprecision(8) << min * m;

    return 0;
}