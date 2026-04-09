/* time complexity nlogn*/

#include <iostream>
#include <vector>
using namespace std;

void merge(int arr[], int start, int mid, int end){
    vector<int>nums(end - start +1); //temp array for storing sorted array
    
    int left = start; int right = mid +1;
    int index = 0;
    
    //fill temp array in sorted order.
    while (left <= mid && right <= end ){
        if (arr[left] <= arr[right]){
            nums[index] = arr[left];
            left++; index++;
        }
        else {
            nums[index] = arr[right];
            right++; index++;
        }
    }
    
    //if some elements remain in left or right side fill them too in the temp array
    while (left <= mid){
        nums[index] = arr[left];
        left++; index++;
    }
    
    while (right <= end){
        nums[index] = arr[right];
        right++; index++;
    }

    //now, copy the sorted number and paste into the real array.
    index = 0;
    for (start; start <= end; start++){
        arr[start] = nums[index];
        index++;
    }
    
}

void mergeSort(int arr[], int start, int end){
    //base case if we reach to the single element return.
    if (start == end) return;
    
    //calcuate mid (this way the integer overflow wont happen).
    int mid = start + (end - start) / 2;
    
    mergeSort(arr, start, mid); //call mergeSort again with the left part of the array
    mergeSort(arr, mid+1, end); //call mergeSort again with the right part of the array
    
    //merge function to merge the logically divided array in sorted forms.
    merge(arr, start, mid , end); 
}

int main()
{
    int arr[] = {65,23,1,6,3,2,78,34,2,32,34};
    int n = sizeof(arr) / sizeof(arr[0]); //to get the size of the array.
    
    mergeSort(arr, 0, n-1); //call mergeSort function by providing the array reference and start and end.
    
    //printing the sorted array.
    for (int i = 0; i < n ; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
