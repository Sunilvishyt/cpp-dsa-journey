// -> we create heap with array because it make easy to work with heap and perform various heap tasks

/**** Heap creation with array*******************************************************************************************************************/
//step up approach of building heap////////////////////////////////////////////////////////////////////////////////////////
//Time Complexity O(nlogn)///////////////////////////////////////////////////////////////////////////////////////

//inserting 1 element takes logn time so, n elements will take nlogn time. 
#include<print>
#include <iostream>
#include <vector>

using namespace std;

class MaxHeap {
    vector<int>arr;
    
    public:
    void insert(int val){
        arr.push_back(val);
        
        int index = arr.size() - 1;
        
        while(index > 0 && arr[(index - 1)/2] < arr[index]){
            swap(arr[(index - 1)/2], arr[index]);
            index = (index - 1) / 2;
        }
        
        print("value inserted : {}", val);
        cout<< "\t";
        print("Array : {}", arr);
        
        cout << endl;
    }
};

int main()
{
    MaxHeap h;
    h.insert(4);
    h.insert(20);
    h.insert(40);
    h.insert(25);
    return 0;
}


//step down approach of building heap////////////////////////////////////////////////////////////////////////////////////////
//Time Complexity O(n)///////////////////////////////////////////////////////////////////////////////////////
#include <print>
#include <vector>
#include <iostream>
using namespace std;

void Heapify(vector<int>&arr, int parentIdx){
    int leftChildIdx = 2*parentIdx+1;
    int rightChildIdx = 2*parentIdx+2;
    
    //find index of biggest child
    int biggestChildIdx;
    
    if (leftChildIdx >= arr.size() && rightChildIdx >= arr.size()) return;
    
    if (leftChildIdx < arr.size() && rightChildIdx >= arr.size()){
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
        Heapify(arr, biggestChildIdx);
    }
}

void BuildMaxHeap(vector<int>&arr){
    for (int i = arr.size()/2-1; i >=0; i--){
        Heapify(arr,i);
    }
}

int main()
{
    vector<int>arr = {3,23,12,89,84,74,34,64,87,109};
    BuildMaxHeap(arr);
    print("array : {}",arr);
    
    return 0;
}
