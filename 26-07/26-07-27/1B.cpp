#include <iostream>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    while(n-- > 0) {
        char str[20] = {'\0'};
        cin >> str;
        int times_of_transform = 0;
        for(int i = 1; i < 20; ++i) {
            if(str[i] <= '9' && str[i] >= '0' && str[i - 1] >= 'A' && str[i - 1] <= 'Z')
                times_of_transform++;
        }
        if(times_of_transform == 1) {
            //BC21形式
            int cols = 0;
            int rows = 0;

            for(int i = 0; str[i] != '\0'; ++i) {
                if(str[i] >= 'A' && str[i] <= 'Z') {
                    int digit_of_cols = str[i] - 'A' + 1;
                    cols = cols * 26 + digit_of_cols;
                } else {
                    int digit_of_rows = str[i] - '0';
                    rows = rows * 10 + digit_of_rows;
                }
            }
            cout << 'R' << rows << 'C' << cols;
        } else {
            //RXCY形式
            int cols = 0;
            int rows = 0;
            int i = 1;
            for(i = 1 ; str[i] != 'C'; ++i) {
                int digit_of_rows = str[i] - '0';
                rows = rows * 10 + digit_of_rows;
            }
            for(i = i + 1 ; str[i] != '\0'; ++i) {
                int digit_of_cols = str[i] - '0';
                cols = cols * 10 + digit_of_cols;
            }
            char str_of_col[20] = {'\0'};
            int index = 0;
            while(cols > 0) {
                cols -= 1;
                int temp = cols % 26;
                str_of_col[index++] = temp + 'A';
                cols /= 26;
            }
            while(--index >= 0)
                cout << str_of_col[index];
            cout << rows;
        }
        if(n != 0)
            cout << endl;
    }

    return 0;
}