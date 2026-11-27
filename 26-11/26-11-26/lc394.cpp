#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> times;
        stack<string> strSt;
        strSt.push("");
        times.push(0);

        for(int i = 0; i < s.size(); ++i) {
            if(s[i] >= '0' && s[i] <= '9') {
                int j = i;
                string numStr;
                while(j < s.size() && s[j] >= '0' && s[j] <= '9') {
                    numStr.push_back(s[j]);
                    j++;
                }
                i = j - 1;
                int n = stoi(numStr);
                times.push(n);
            } else if(s[i] == '[') {
                strSt.push("");
            } else if(s[i] == ']') {
                int t = times.top();
                times.pop();

                string copy = strSt.top();
                
                for(int i = 0; i < t - 1; ++i) {
                    strSt.top().append(copy);
                }
                string cur = strSt.top();
                strSt.pop();
                strSt.top() += cur;
                
            } else if(s[i] >= 'a' && s[i] <= 'z') {
                strSt.top().push_back(s[i]);
            }
        }
        string res = strSt.top();
        return res;
    }
};

int main(void) {
    string s = "2[abc]3[cd]ef";
    Solution e;
    string res = e.decodeString(s);

    return 0;
}