#include<iostream>
using namespace std;

void quick_sort(int arr[], int l, int r)
{
    while(l < r)
    {
        int mid = l + (r - l) / 2;

        int a = arr[l];
        int b = arr[mid];
        int c = arr[r];

        int pivot;

        if((a >= b && a <= c) || (a >= c && a <= b))
            pivot = a;
        else if((b >= a && b <= c) || (b >= c && b <= a))
            pivot = b;
        else
            pivot = c;

        int lt = l;
        int i  = l;
        int gt = r;

        while(i <= gt)
        {
            if(arr[i] < pivot)
            {
                std::swap(arr[lt], arr[i]);
                lt++;
                i++;
            }
            else if(arr[i] > pivot)
            {
                std::swap(arr[i], arr[gt]);
                gt--;
            }
            else
            {
                i++;
            }
        }

        if(lt - l < r - gt)
        {
            quick_sort(arr, l, lt - 1);
            l = gt + 1;
        }
        else
        {
            quick_sort(arr, gt + 1, r);
            r = lt - 1;
        }
    }
}

int main(void){
	int arr[] = {4, 3, 2, 1};
	quick_sort(arr, 0, 3);
	for(int i = 0; i < 4; ++i)
		cout << arr[i];


	return 0;
}
