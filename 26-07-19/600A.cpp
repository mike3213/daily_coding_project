#include <iostream>
using namespace std;
int main(){
    char inputStr[100001] = "\0";
    cin >> inputStr;
    int index = -1;
    char numberStr[100001] = "\0";
    char latinStr[100001] = "\0";
    int index1 = 0, index2 = 0;
    
    do {
        bool isNumStr = true;
        int start = index;
        index++;
        while(inputStr[index] != ',' && inputStr[index] != ';' && inputStr[index] != '\0'){
            if(isNumStr == true && (inputStr[index] > '9' || inputStr[index] < '0'))
                isNumStr = false;
            index++;
        }
        int end = index;

        if(isNumStr && inputStr[start + 1] == '0' && end - start > 2)
            isNumStr = false;

        if(!isNumStr || start + 1 == end){
            for(int i = start + 1; i < end; ++i){
                latinStr[index2] = inputStr[i];
                index2++;
            }
            latinStr[index2] = ',';
            index2++;
        } else {
            for(int i = start + 1; i < end; ++i){
                numberStr[index1] = inputStr[i];
                index1++;
            }
            numberStr[index1++] = ',';
        }
    } while(inputStr[index] != '\0');

    latinStr[index2 - 1] = '\0';
    numberStr[index1 - 1] = '\0';

    if(index1 != 0)
        cout << "\"" << numberStr << "\"" << endl;
    else 
        cout << "-" << endl;
    if(index2 != 0)
        cout << "\"" << latinStr << "\"" << endl;
    else 
        cout << "-" << endl;
    
    return 0;
}