#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if(n % 2 != 0)
            return false;
        int i = 0;
        vector<char> vt;
        while(i < n) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                vt.emplace_back(s[i]);
            else {
                if(vt.empty())
                    return false;
                switch(s[i]) {
                    case ')':
                        if(vt.back() != '(')
                            return false;
                        else 
                            vt.pop_back();
                        break;
                    case ']': 
                        if(vt.back() != '[')
                            return false;
                        else 
                            vt.pop_back();
                        break;
                    case '}': 
                        if(vt.back() != '{')
                            return false;
                        else 
                            vt.pop_back();
                        break;
                    default:
                        return false;
                }
            }
            ++i;
        }
        if(vt.empty())
            return true;
        else
            return false;
    }
};


int main(void) {


    return 0;
}