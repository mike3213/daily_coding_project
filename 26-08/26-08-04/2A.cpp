#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;
int main() {
    unordered_map<string, int> players;
    players.reserve(1000);
    int rounds = 0;
    cin >> rounds;
    vector<pair<string, int>> input;
    for(int i = 0; i < rounds; ++i) {
        input.resize(input.size() + 1);
        cin >> input.at(i).first >> input.at(i).second;
    }

    for(int i = 0; i < rounds; ++i) {
        string str = input.at(i).first;
        int scores = input.at(i).second;
        if(players.count(str)) {
            auto it = players.find(str);
            it->second += scores;
        } else {
            players.emplace(str, scores);
        }
    }
    int max = 0;
    for(auto &x : players) {
        if(x.second > max) {
            max = x.second;
        }
    }
    unordered_map<string, int> same;
     for(auto &x : players) {
        if(x.second == max) {
            same.emplace(x);
        }
        x.second = 0;
    }
    if(same.size() == 1)
        cout << same.begin()->first;
    else {
        for(int i = 0; i < rounds; ++i) {
            string str = input.at(i).first;
            int scores = input.at(i).second;
            players.at(str) += scores;
            if(players.at(str) >= max && same.count(str) != 0) {
                cout << str;
                break;
            }
        }
    }

    return 0;
}