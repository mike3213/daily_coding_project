#include <iostream>

using namespace std;

int main() {
    int layers = 0;
    cin >> layers;
    for(int i = 1; i <= layers; ++i) {
        if(i % 2 != 0)
            cout << "I hate ";
        else 
            cout << "I love ";
        
        if(i != layers)
            cout << "that ";
        else 
            cout << "it";
    }

    return 0;
}