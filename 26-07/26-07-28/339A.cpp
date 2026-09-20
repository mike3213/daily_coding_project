#include <iostream>
#include <algorithm>
using namespace std;

void quick_sort(int num[], int left, int right) {
    while(left < right) {
        int L = left, R = right, M = L + (R - L) / 2;
        if(num[L] > num[M]) swap(num[L], num[M]);
        if(num[L] > num[R]) swap(num[L], num[R]);
        if(num[M] > num[R]) swap(num[M], num[R]);
        int pivot = num[M];
    
        int lt = left, gt = right, i = left;
        while(i <= gt) {
            if(num[i] < pivot) {
                swap(num[lt], num[i]);
                lt++, i++;
            } else if(num[i] == pivot)
                i++;
            else {
                swap(num[gt], num[i]);
                gt--;
            }
        }
        if(lt - 1 - left + 1 < right - gt - 1 + 1) {
            quick_sort(num, left, lt - 1);
            left = gt + 1;
        }
        else {
            quick_sort(num, gt + 1, right);
            right = lt - 1;
        }
    }
}

int main() {
    int summands[101] = {'\0'};
    int index = 0;
    char ch = '\0';
    while(cin >> ch) {
        if(ch <= '9' && ch >= '0')
            summands[index++] = static_cast<int>(ch) - static_cast<int>('0');
    }
    quick_sort(summands, 0, index - 1);

    for(int i = 0; i < index; ++i) {
        cout << summands[i];
        if(i != index - 1)
            cout << '+';
    }

    return 0;
}