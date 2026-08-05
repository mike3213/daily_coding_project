#include <iostream>
#include <string>
using namespace std;
int main() {
    string str;
    cin >> str;
    unsigned int size = str.size();
    for(int i = 0; i < size; ++i) {
        if(str.at(i) == '0') {
            str.erase(i, 1);
            break;
        }
    }
    if(str.size() == size)
        str.pop_back();
    cout << str;
    
    return 0;
}