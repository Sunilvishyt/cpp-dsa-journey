
#include <iostream>
#include <vector>
using namespace std;

int getPivot(vector<int>&arr, int start, int end){
    int pos = start;
    for (int i = start; i <= end; i++){
        if (arr[i] <= arr[end]){
            swap(arr[i], arr[pos]);
            pos++;
        }
    }
    return pos -1;
}

void quickSort(vector<int>&arr, int start,int end){
    if (start >= end) return;
    
    int pivot = getPivot(arr, start, end);
    quickSort(arr, start, pivot-1);
    quickSort(arr, pivot+1, end);
}

int main()
{
    vector<int>arr = {10,3,5,2,8,7,1,4,9};
    quickSort(arr, 0, arr.size()-1);
    
    for (auto i : arr){
        cout << i << " ";
    }
    
    return 0;
}

//quicksort has the average/best case TC of n^2 which happens only when the array is already sorted, or we have to sort the descending order array into ascending
//or vice versa. and for all other cases the TC is nlogn and,
//SC is logn for average/best case but n for worst case.
