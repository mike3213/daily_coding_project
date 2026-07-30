#include <iostream>
using namespace std;

int main() {
    int n = 0, m = 0, a = 0, b = 0;
    cin >> n >> m >> a >> b;
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

    return 0;
}