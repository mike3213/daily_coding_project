#include <iostream>
#include <stack>
#include <set>
using namespace std;

int main() {
    int n = 0, m = 0, a = 0, b = 0;
    cin >> n >> m >> a >> b;
    int min_expence = 1e9;
    set<pair<int, int>> visited;
    stack<pair<int, int>> tickets;
    tickets.emplace(0, 0);
    visited.emplace(0, 0);
    while(!tickets.empty()) {
        pair<int, int> temp = tickets.top();
        tickets.pop();
        if(temp.first + temp.second * m >= n ) {
            if(temp.first * a + temp.second * b < min_expence)
                min_expence = temp.first * a + temp.second * b;
        } else {
            if(visited.count(make_pair(temp.first, temp.second + 1)) < 1) {
                tickets.emplace(temp.first, temp.second + 1);
                visited.emplace(temp.first, temp.second + 1);
            }
            if(visited.count(make_pair(temp.first + 1, temp.second)) < 1) {
                tickets.emplace(temp.first + 1, temp.second);
                visited.emplace(temp.first + 1, temp.second);
            }
        }
    }

    cout << min_expence;

    return 0;
}

 /***********************************
    int max_num_of_m_tickets = n / m;
    if(n % m != 0)
        max_num_of_m_tickets++;
    int m_ticket = max_num_of_m_tickets;
    int one_ticket = 0;
    int min_expence = 1e9;
    while(m_ticket >= 0) {
        int cur_expence = m_ticket * b + one_ticket * a;
        if(cur_expence < min_expence)
            min_expence = cur_expence;
        m_ticket -= 1;
        one_ticket = n - m_ticket * m;
    }

    cout << min_expence;
    *************************************/