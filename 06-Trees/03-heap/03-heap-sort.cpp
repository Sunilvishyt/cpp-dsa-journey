// T.C. -> o(nlogn)

#include <print>
#include <vector>
#include <iostream>
using namespace std;

//Heapify just needs arr, parentIdx, n and it will put the parent in correct place, whether we give the top as parent or any other node. 
void Heapify(vector<int>&arr, int parentIdx, int n){
    int leftChildIdx = 2*parentIdx+1;
    int rightChildIdx = 2*parentIdx+2;
    
    //find index of biggest child
    int biggestChildIdx;
    
    if (leftChildIdx >= n && rightChildIdx >= n) return;
    
    if (leftChildIdx < n && rightChildIdx >= n){
        biggestChildIdx = leftChildIdx;
    }
    else {
        int maxChildValue = max(arr[leftChildIdx], arr[rightChildIdx]);
        if (maxChildValue == arr[leftChildIdx]) biggestChildIdx = leftChildIdx;
        else biggestChildIdx = rightChildIdx;
    }
    
    //if child is greater than parent we have to swap
    if (arr[biggestChildIdx] > arr[parentIdx]){
        swap(arr[biggestChildIdx], arr[parentIdx]);
        Heapify(arr, biggestChildIdx, n);
    }
}

void BuildMaxHeap(vector<int>&arr){
    for (int i = arr.size()/2-1; i >= 0; i--){
        Heapify(arr, i, arr.size());
    }
}

void SortArray(vector<int>&arr){
    //put the front element of max heap at the last (which will definately by greaters of the heap) and shrink the array size by 1, means the last element is in correct position other have to be made in correct form. thats why we run Heapify 
    for (int i = arr.size()-1; i > 0; i--){
        swap(arr[0], arr[i]);
        Heapify(arr, 0, i);
    }
}

int main()
{
    vector<int>arr = {3,23,12,89,84,74,34,64,87,109};
    //first build the max heap. o(n) T.C.
    BuildMaxHeap(arr);
    print("Max Heap : {}",arr);
    
    cout << endl;
    
    //then, sort using heap sort. 0(nlogn) T.C.
    SortArray(arr);
    print("sorted : {}", arr);
    
    
    return 0;
}
