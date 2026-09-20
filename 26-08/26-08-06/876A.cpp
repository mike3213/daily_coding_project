#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    int n = 0, a = 0, b = 0, c = 0;
    cin >> n >> a >> b >> c;
    int cur_pos = 1;
    int sum_distance = 0;
    while (--n > 0)
    {
        if (cur_pos == 1)
        {
            if (a < b)
            {
                cur_pos = 2;
                sum_distance += a;
            }
            else
            {
                cur_pos = 3;
                sum_distance += b;
            }
        }
        else if (cur_pos == 2)
        {
            if (c < a)
            {
                cur_pos = 3;
                sum_distance += c;
            }
            else
            {
                cur_pos = 1;
                sum_distance += a;
            }
        }
        else if (cur_pos == 3)
        {
            if (c < b)
            {
                cur_pos = 2;
                sum_distance += c;
            }
            else
            {
                cur_pos = 1;
                sum_distance += b;
            }
        }
    }
    cout << sum_distance;

    return 0;
}