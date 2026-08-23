// -> we create heap with array because it make easy to work with heap and perform various heap tasks

/**** Heap creation with array*******************************************************************************************************************/
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

