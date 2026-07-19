#include<iostream>
using namespace std;
int main(){
    unsigned int n = 0;
    cin >> n;
    //hash map to check weather Latin letter is existed 
    unsigned short map[26] = {0};
    char ch = '\0';
    unsigned short ascII_A = static_cast<unsigned short>('A');
    unsigned short ascII_a = static_cast<unsigned short>('a');
    unsigned short ascII_Z = static_cast<unsigned short>('Z');
    unsigned short ascII_z = static_cast<unsigned short>('z');
    unsigned int count = 0;
    for(int i = 0; i < n; ++i){
        cin >> ch;
        unsigned short ascII = static_cast<int>(ch);
        if( ascII >=  ascII_A && ascII <= ascII_Z){
            ascII = ascII - ascII_A + ascII_a;
        }
        unsigned short index = ascII - ascII_a;
        if(map[index] == 0){
            map[index] = 1;
            count++;
        }
    }

    if(count == 26)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}