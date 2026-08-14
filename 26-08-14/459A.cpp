#include <iostream>
#include <vector>
using namespace std;
int main() {
    pair<int, int> pos1, pos2, pos3(1e9, 1e9), pos4(1e9, 1e9);
    cin >> pos1.first >> pos1.second >> pos2.first >> pos2.second;
    if(pos1.first == pos2.first) {
        int side_len = pos1.second - pos2.second;
        if(side_len < 0)
            side_len *= -1;
        pos3.first = pos1.first + side_len;
        pos4.first = pos3.first;
        pos3.second = pos1.second, pos4.second = pos2.second;
    } else if(pos1.second == pos2.second) {
        int side_len = pos1.first - pos2.first;
        if(side_len < 0)
            side_len *= -1;
        pos3.first = pos1.first;
        pos4.first = pos2.first;
        pos3.second = pos1.second + side_len;
        pos4.second = pos2.second + side_len;
    } else {
        int len = pos1.first - pos2.first, width = pos1.second - pos2.second;
        if(len < 0)
            len *= -1;
        if(width < 0)
            width *= -1;
        if(len == width) {
            pos3.first = pos1.first;
            pos3.second = pos2.second;
            pos4.first = pos2.first;
            pos4.second = pos1.second;
        }
    }
    if(pos3.first != 1e9)
        cout << pos3.first << ' ' << pos3.second << ' '
             << pos4.first << ' ' << pos4.second;
    else 
        cout << -1;
        
    return 0;
}