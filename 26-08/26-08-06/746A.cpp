#include <iostream>
#include <vector>
using namespace std;
int main() {
    int a = 0, b = 0, c = 0;
    cin >> a >> b >> c;
    int pieces_a = a, pieces_b = b / 2, pieces_c = c / 4;
    int min = pieces_a;
    if(min > pieces_b)
        min = pieces_b;
    if(min > pieces_c)
        min = pieces_c;
    cout << 7 * min;

    return 0;
}