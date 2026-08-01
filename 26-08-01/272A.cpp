#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num_of_friends = 0;
    cin >> num_of_friends;
    int sum = 0;
    for(int i = 0; i < num_of_friends; ++i) {
        int t = 0;
        cin >> t;
        sum += t;
    }

    int answer_num = 0;
    for(int x = 1; x <= 5; ++x) {
        int total = sum + x;
        if((total - 1) % (num_of_friends + 1) != 0)
            answer_num++;
    }
    
    cout << answer_num;

    return 0;
}