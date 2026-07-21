#include <iostream>
using namespace std;
int main(){
    int n = 0;
    cin >> n;
    int nodes[101][2] = {0}; //store the input previous and next node of current node.
    int headNode[101] = {0};//record the head node of each doubly linked list when input 
    int headNodeNum = 0;
    for(int i = 1; i <= n; ++i) {
        cin >> nodes[i][0] >> nodes[i][1];
        if(nodes[i][0] == 0) {
            headNode[headNodeNum++] = i;
        }
    }
    
    int sequenceUnited[100] = {0};
    int pointer = 0;
    for(int i = 0; i < headNodeNum; ++i) {
        int index = headNode[i];
        while(index != 0) {
            sequenceUnited[pointer++] = index;
            index = nodes[index][1];
        }
    }

    for(int i = 0; i < pointer; ++i) {
        int t = sequenceUnited[i];
        if(nodes[t][1] == 0) {
            if(i + 1 < pointer) {
                nodes[t][1] = sequenceUnited[i + 1];
                nodes[sequenceUnited[i + 1]][0] = t;
            }
        }
    }
    for(int i = 1; i <= n; ++i) {
        cout << nodes[i][0] << " " << nodes[i][1];
        if(i != n)
            cout << "\n";
    }

    return 0;
}