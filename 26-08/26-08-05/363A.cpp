#include <iostream>
#include <vector>
using namespace std;

void print(unsigned int &num) {
    if(num == 0)
        cout << "O-|-OOOO";
    if(num == 1)
        cout << "O-|O-OOO";
    if(num == 2)
        cout << "O-|OO-OO";
    if(num == 3)
        cout << "O-|OOO-O";
    if(num == 4)
        cout << "O-|OOOO-";
    if(num == 5)
        cout << "-O|-OOOO";
    if(num == 6)
        cout << "-O|O-OOO";
    if(num == 7)
        cout << "-O|OO-OO";
    if(num == 8)
        cout << "-O|OOO-O";
    if(num == 9)
        cout << "-O|OOOO-";
}

int main() {
    unsigned int num = 0;
    cin >> num;
    if(num == 0)
        print(num);
    vector<unsigned int> digits;
    while(num > 0) {
        unsigned short digit = num % 10;
        digits.emplace_back(digit);
        num /= 10;
    }
    size_t size = digits.size();
    for(int i = 0; i < size; ++i) {
        print(digits.at(i));
        if(i != size - 1)
            cout << '\n';
    }

    return 0;
}