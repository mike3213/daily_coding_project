#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int h1 = 0, m1 = 0, h2 = 0, m2 = 0;
    char ch = '\0';
    cin >> h1 >> ch >> m1 >> h2 >> ch >> m2;
    int h_diff = 0, m_diff = 0;
    if(m2 >= m1)
        m_diff = m2 - m1;
    else {
        m_diff = m2 + 60 - m1;
        h2--;
    }
    h_diff = h2 - h1;

    int total_minutes = h_diff * 60 + m_diff;
    int half_time = total_minutes / 2;
    int add_m = half_time % 60;
    int add_h = (half_time - add_m) / 60;
    int h = h1 + add_h;
    int m = m1 + add_m;
    if(m >= 60) {
        m -= 60;
        h++;
    }

    cout << setfill('0')
         << setw(2) << h 
         << ':' 
         << setw(2) << m;

    return 0;
}