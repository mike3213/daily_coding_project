#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    int n = 0;
    cin >> n;
    while(n-- > 0) {
        string in = "";
        string res = "";
        cin >> in;
        for(int i = 0; i < in.size(); i += 2) {
            res.push_back(in.at(i));
        }
        res.push_back(in.at(in.size() - 1));
        cout << res;
        if(n > 0)
            cout << '\n';
    }


    return 0;
}