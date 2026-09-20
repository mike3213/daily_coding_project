#include<iostream>
using namespace std;
/*
void quick_sort(unsigned int arr[][2], int l, int r){
	while(l < r){
		int mid = l + (r - l) / 2;
		int a = arr[l][0], b = arr[mid][0], c = arr[r][0];
		int pivot = 0;
		if(a >= b && a <= c || a >= c && a <= b)
			pivot = a;
		else if(b >= a && b <= c || b >= c && b <= a)
			pivot = b;
		else
			pivot = c;

		int gt = r, lt = l;
		int i = l;
		while(i <= gt){
			if(arr[i][0] < pivot){
				int t1 = arr[lt][0], t2 = arr[lt][1];
				arr[lt][0] = arr[i][0], arr[lt][1] = arr[i][1];
				arr[i][0] = t1, arr[i][1] = t2;
				lt++;
				i++;
			} else if(arr[i][0] > pivot){
				int t1 = arr[gt][0], t2 = arr[gt][1];
				arr[gt][0] = arr[i][0], arr[gt][1] = arr[i][1];
				arr[i][0] = t1, arr[i][1] = t2;
				gt--;
			} else {
				i++;
			}
		}
		if(lt - l < r - gt){
			quick_sort(arr, l, lt - 1);
			l = gt + 1;
		} else {
			quick_sort(arr, gt + 1, r);
			r = lt - 1;
		}
	}
}
*/
void merge(unsigned int arr[][2], int l, int mid, int r,unsigned int temp[][2]){
	int i = l, j = mid, k = l;
	while(i < mid && j < r){
		if(arr[i][0] <= arr[j][0]){
			temp[k][0] = arr[i][0], temp[k][1] = arr[i][1];
			k++, i++;
		} else {	
			temp[k][0] = arr[j][0], temp[k][1] = arr[j][1];
			k++, j++;
		}
	}
	while(i < mid){
		temp[k][0] = arr[i][0], temp[k][1] = arr[i][1];
		k++, i++;
	}
	while(j < r){
		temp[k][0] = arr[j][0], temp[k][1] = arr[j][1];
		k++, j++;
	}
	for(int p = l; p < r; ++p){
		arr[p][0] = temp[p][0], arr[p][1] = temp[p][1];
	}
}

void merge_sort(unsigned int arr[][2], int n){
	unsigned int temp[1000][2] = {0};
	for(int len = 1; len < n; len *= 2){
		for(int l = 0; l < n; l += 2 * len){
			int mid = l + len > n ? n : l + len;
			int r = l + 2 * len > n ? n : l + 2 * len;
			merge(arr, l, mid, r, temp);
		}
	}
}


int main(void){
	unsigned int s = 0, n = 0;
	cin >> s >> n;
	unsigned int dragons[1000][2] = {{0, 0}};
	for(int i = 0; i < n; ++i){
		cin >> dragons[i][0] >> dragons[i][1];
	}
	/*
	quick_sort(dragons, 0, n - 1);
	*/
	merge_sort(dragons, n);
	for(int i = 0; i < n; ++i){
		if(s > dragons[i][0]){
			s += dragons[i][1];
		} else {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";

	return 0;
}









