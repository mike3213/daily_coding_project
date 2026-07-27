#include <iostream>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    int exercise_count[3] = {0};
    int index = 0;
    while(n-- > 0) {
        int input = 0;
        cin >> input;
        exercise_count[index++] += input;
        index %= 3;
    }

    int max_value_index = 0;
    if(exercise_count[0] < exercise_count[1])
        max_value_index = 1;
    if(exercise_count[2] > exercise_count[max_value_index])
        max_value_index = 2;
    switch(max_value_index) {
        case 0: cout << "chest";
            break;
        case 1: cout << "biceps";
            break;
        case 2: cout << "back";
            break;
    }

    return 0;
}