#include <iostream>
using namespace std;

//pop stack. image a binary tree, every child node means different choices.
// every node means a state node, stack is the container that contains all states.
// when the state node is unsuitable for the request of the answer of problems
// so it means we have checked all states when the stack is empty
// pop means current state node is unsuitable then try another one
// push means new state node matching different choices namely different situation.

bool wildcardMatch(const char* pattern, const char* text) {
    int stack[200000 * 2] = {0};
    int p = 0;
    stack[p++] = 0, stack[p++] = 0;
    
    while(p > 0) {
        int i = stack[p - 2], j = stack[p - 1];
        p -= 2;

        // both are the end
        if(pattern[i] == '\0' && text[j] == '\0')
            return true;
        // any one is the end
       
        // both are not the end
        if(pattern[i] == '*') {
            stack[p] = i + 1;
            stack[p + 1] = j;
            p += 2;
            if(text[j] != '\0') {
                stack[p] = i;
                stack[p + 1] = j + 1;
                p += 2;        
            }
        } else {
            if(pattern[i] == text[j]) {
                stack[p] = i + 1;
                stack[p + 1] = j + 1;
                p += 2;
            } else
                continue;
        } 
    }

    return false;
}

int main() {
    int patternLen = 0, textLen = 0;
    cin >> patternLen >> textLen;
    char pattern[200001] = {'\0'}, text[200001] = {'\0'};
    cin >> pattern >> text;
    
    //bool isMatched = wildcardMatch(pattern, text);
    bool isMatched = false;
    
    int i = 0, j = 0;
    while(i < patternLen && j < textLen && pattern[i] == text[j])
        i++, j++;
    if(i >= patternLen && j >= textLen)
        isMatched = true;
    else if(i < patternLen && j >= textLen) {
        if(i == patternLen - 1 && pattern[i] == '*')
            isMatched = true;
    } else if(pattern[i] == '*') {
        if(i == patternLen - 1)
            isMatched = true;
        else {
            int p1 = patternLen - 1, p2 = textLen - 1;
            while(p1 > i && p2 >= i) {
                if(pattern[p1] == text[p2])
                    p1--, p2--;
                else
                    break;
            }
            if(p1 == i)
                isMatched = true;
        }
    }
        

    if(isMatched)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}