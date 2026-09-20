#include<iostream>
using namespace std;
int main(){
    char inputString[100000] = "\0";
    cin >> inputString;
    bool flagAB = false, flagBA = false;
    int indexAB_1 = -1, indexAB_2 = -1, indexBA_1 = -1, indexBA_2 = -1;
    unsigned int i = 0;

    while(inputString[i + 1] != '\0'){
        if(inputString[i] == 'A' && inputString[i + 1] == 'B'){
            if(!flagAB)
                indexAB_1 = i;
            flagAB = true;
            indexAB_2 = i;
        } else if(inputString[i] == 'B' && inputString[i + 1] == 'A'){
            if(!flagBA)
                indexBA_1 = i;
            flagBA = true;
            indexBA_2 = i;
        }
        i++;
        if(flagAB && flagBA){
            int temp1 = indexBA_2 - indexAB_1,  temp2 = indexAB_2 - indexBA_1;
            if(temp1 < 0)
                temp1 = -temp1;
            if(temp2 < 0)
                temp2 = -temp2;
            if(temp1 != 1 || temp2 != 1){
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";

    return 0;
}