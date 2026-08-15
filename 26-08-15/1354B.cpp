#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    int cases = 0;
    cin >> cases;
    while (cases-- > 0)
    {
        string str;
        cin >> str;
        vector<int> cnt(3, 0);
        int left = 0, right = 0, min_size = 1e9;
        while (right < str.size())
        {
            if (str[right] == '1')
                cnt[0]++;
            else if (str[right] == '2')
                cnt[1]++;
            else if (str[right] == '3')
                cnt[2]++;
            if (cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0)
            {
                while (cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0)
                {
                    if (str[left] == '1')
                        cnt[0]--;
                    else if (str[left] == '2')
                        cnt[1]--;
                    else if (str[left] == '3')
                        cnt[2]--;
                    left++;
                }
                int cur_min_size = right - (left - 1) + 1;
                if (cur_min_size < min_size)
                    min_size = cur_min_size;
            }

            right++;
        }
        if(min_size == 1e9)
            cout << 0;
        else 
            cout << min_size;
        if (cases != 0)
            cout << '\n';
    }

    return 0;
}