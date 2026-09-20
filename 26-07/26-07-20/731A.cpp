#include <iostream>
using namespace std;
int main() {
    char str[101];
    cin >> str;
    int minimum = 0;

    char current_ch = 'a';
    for(int i = 0; str[i] != '\0'; ++i){
        char next_ch = str[i];
        int distance_clockwise = static_cast<int>(current_ch) - static_cast<int>(next_ch);
        if(distance_clockwise < 0)
            distance_clockwise *= -1;

        int distance_counterClockwise = 26 - distance_clockwise;
        minimum += distance_clockwise > distance_counterClockwise ? distance_counterClockwise : distance_clockwise;
    
        current_ch = next_ch;
    }

    cout << minimum;

    return 0;
}