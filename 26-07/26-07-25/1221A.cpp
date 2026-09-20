#include <iostream>
using namespace std;

//firstly, sort the multiset, then, select two biggest elements of the multiset every time
//judge wheather the two elements can be merged into one element, mark one position of the two merged elements -1
//repeat above operations until no more two element can be merged 
//output yes if occur 2048 in above process otherwise output no  

int main() {
    int queries = 0;
    cin >> queries;

    bool answer[100] = {false};
    int index = 0;

    while(queries-- > 0) {
        bool isExisted = false;
        int n = 0;
        cin >> n;
        unsigned int multiset[100] = {0};

        for(int i = 0; i < n; ++i) {
            cin >> multiset[i];
        }
        for(int i = 0; i < n; ++i) {
            if(multiset[i] == 2048) {
                isExisted = true;
                break;
            }
        }
        
        if(!isExisted && n > 1) {
            for(int i = 1; i < n; ++i) {
                int t = multiset[i];
                int j = i;
                while(j > 0 && t > multiset[j - 1]) {
                    multiset[j] = multiset[j - 1];
                    j--;
                }
                multiset[j] = t;
            }
    
            
            int p1 = 0, p2 = 1;
            while(p1 < n && p2 < n) {
                if(multiset[p1] == multiset[p2]) {
                    multiset[p1] *= 2;
                    if(multiset[p1] == 2048) {
                        isExisted = true;
                        break;
                    }
                    for(int i = p2; i < n - 1; ++i) {
                        multiset[i] = multiset[i + 1];
                    }

                    n--;
                    if(p1 > 0) {
                        p1--, p2--;
                    }
                } else 
                    p1++, p2++;
            }
        }

        if(isExisted)
            answer[index] = true;
        index++;
    }

    for(int i = 0; i < index; ++i) {
        if(answer[i])
            cout << "YES";
        else
            cout << "NO";
        if(i != index - 1)
            cout << endl;
    }

    return 0;
}


/****************************************************
int main() {
    //firstly, chech if there is 2048 in multiset, if exists, print yes, otherwise
    //for 1 to n: check if there is element equals to multiset[i], if exists, merge into multiset and 
    //mark one of them -1 means this element is invalid. 
    //check if there is 2048 after done above operation, if no, keep doing above operation until no element existing
    //multiset, once confirm 2048 occuring end this operation print yes.

    int queries = 0;
    cin >> queries;

    int n = 0;
    unsigned int multiset[100] = {0};
    bool answer[100] = {false};
    int index = 0;

    for(int i = 0; i < queries; ++i) {
        cin >> n;
        for(int j = 0; j < n; ++j) {
            cin >> multiset[j];
        }

        bool is2048 = false;
        bool canMerge = true;
        bool merged = false;
        
        while (!is2048 && canMerge)
        {
            for(int j = 0; j < n; ++j) {
                if(multiset[j] == 2048) {
                    is2048 = true;
                    break;
                } else if(multiset[j] > 2048)
                    multiset[j] = -1;
            }
            
            for(int j = 0; j < n; ++j) {
                if(multiset[j] == -1)
                    continue;
                for(int k = 0; k < n; ++k) {
                    if(k != j && multiset[j] == multiset[k]) {
                        merged = true;
                        multiset[k] *= 2;
                        multiset[j] = -1;
                        if(multiset[k] == 2048) {
                            is2048 = true;
                            break;
                        }
                    }
                }
                if(is2048)
                    break;
            }            
            if(!merged) {
                canMerge = false;
                break;
            }
        }
        
        if(is2048)
            answer[index] = true;
        index++;
    }

    for(int i = 0; i < index; ++i) {
        if(answer[i])
            cout << "YES";
        else
            cout << "NO";
        if(i != index - 1)
            cout << endl;
    }

    return 0;
}
********************************************************/