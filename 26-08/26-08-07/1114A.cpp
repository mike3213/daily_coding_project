#include <iostream>
#include <vector>
using namespace std;
int main() {
    int x = 0, y = 0, z = 0;
    int green = 0, purple = 0, black = 0;
    cin >> x >> y >> z
        >> green >> purple >> black;
    green -= x;
    if(green < 0)
        cout << "NO";
    else {
        int remainder = purple + green - y;
        if(remainder < 0)
            cout << "NO";
        else {
            remainder = remainder + black - z;
            if(remainder < 0)
                cout << "NO";
            else 
                cout << "YES";
        }
    } 

    return 0;
}