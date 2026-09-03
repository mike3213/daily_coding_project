#include <bits/stdc++.h>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0;
        cin >> n;
        vector<int> num(n, 0);
        long long sum = 0;
        for(auto &x : num) {
            cin >> x;
            sum += x;
        }
        // ai + aj = 2 * aver
        int double_average = sum * 2LL / n;
        if(1LL * double_average * n != sum * 2LL) {
            cout << 0;
        } else {
            sort(num.begin(), num.end());
            long long ans = 0, i = 0;
            for(i = 0; num[i] * 2 < double_average; ++i) {
                int x = double_average - num[i];
                int left = i + 1, right = n;
                while(left < right) {
                    int mid = left + (right - left) / 2;
                    if(num[mid] < x) {
                        left = mid + 1;
                    } else if(num[mid] > x) {
                        right = mid;
                    } else {
                        int cnt_L = 0, cnt_R = 0;
                        for(int j = mid - 1; j >= left; --j) {
                            if(num[j] == num[mid])
                                cnt_L++;
                            else
                                break;
                        }
                        for(int j = mid + 1; j < right; ++j) {
                            if(num[j] == num[mid])
                                cnt_R++;
                            else
                                break;
                        }
                        int identical = 0;
                        for(int j = i + 1; num[j] * 2 < double_average; ++j) {
                            if(num[j] == num[i])
                                identical++;
                            else
                                break;
                        }
                        ans += (1LL + identical) * (1LL + cnt_L + cnt_R);
                        i += identical;
                        break;
                    }
                }
            }
            int identical = 0;
            while(i < n && num[i++] * 2 == double_average) {
                identical++;
            }
            ans += 1LL * identical * (identical - 1) / 2;

            cout << ans;
            /*int i = 0, j = n - 1;
            long long ans = 0;
            while(i < j) {
                if(i < j && num[i] + num[j] > double_average) {
                    j--;
                }
                else if(i < j && num[i] + num[j] < double_average) {
                    i++;
                }
                else if(i < j && num[i] + num[j] == double_average) {
                    long long cnt_i = 0;
                    for(int k = i + 1; k < j; ++k) {
                        if(num[k] == num[i])
                            cnt_i++;
                    }
                    long long cnt_j = 0;
                    for(int k = j - 1; k > i; --k) {
                        if(num[k] == num[j])
                            cnt_j++;
                    }
                    if(cnt_i + cnt_j <= j - i - 1) {
                        ans += (cnt_i + 1) * (cnt_j + 1);
                        i += (cnt_i + 1), j -= (cnt_j + 1);
                    } else {
                        long long t = cnt_i + 2;
                        ans += t * (t - 1) / 2;
                        break;
                    }
                }
            }
            cout << ans;
            */
        }
        
        if(cases > 0)
            cout << '\n';
    }




    return 0;
}