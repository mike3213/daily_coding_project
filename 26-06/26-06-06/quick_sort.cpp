#include<iostream>
using namespace std;
void quick_sort(int arr[], int l, int r);
int main(void){
	int arr[] ={5, 4, 3, 2, 1, 0};
	quick_sort(arr, 0, 5);
	for(int i = 0; i < 6; ++i)
		cout << arr[i];
	return 0;
}

void quick_sort(int arr[], int l, int r){
	while(l < r){
		
	//三数取中
	int mid = l + (r - l) / 2;
	int a = arr[l], b = arr[mid], c = arr[r];
	int pivot = 0;
	if(a >= b && a <= c || a >= c && a <= b)
		pivot = a;
	else if(b >= a && b <= c || b >= c && b <= a)
		pivot = b;
	else
		pivot = c;
	//三路快排
	//lt左边全是小于，gt右边全是大于，初始时为l, r
	//即lt指向小于pivot的下一个位置，gt指向大于pivot的左边“下一个存放位置”
	int lt = l, gt = r;
	for(int i = lt; i <= gt; ++i){//从头开始，将数据分区，直到遇到右边边界gt
		if(arr[i] < pivot){
			int temp = arr[lt];
			arr[lt] = arr[i];
			arr[i] = temp;
			lt++;
		} else if(arr[i] > pivot){
			int temp = arr[gt];
			arr[gt] = arr[i];
			arr[i] = temp;
			gt--;
			i--;
		}
	}
	//递归小区间＋尾递归
		if(lt - l > r - gt){
			quick_sort(arr, gt + 1, r);
			r = lt - 1;
		} else {
			quick_sort(arr, l, lt - 1);
			l = gt + 1;
		}
	}
}
