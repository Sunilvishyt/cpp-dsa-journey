////////////////////////Linear Search with recursion \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
#include <iostream>
using namespace std;

int linearSearch(const int arr[], int item, int index){
    if (index == -1){
        return -1;
    }
    
    if (item == arr[index]) return index;
    
    return linearSearch(arr, item, index - 1);
}

int main()
{    
    int arr[] = {1,2,3,4,5,6,7};
    int item = 3;
    int ans = linearSearch(arr, item, sizeof(arr) / sizeof(arr[0])-1);
    cout << ans;
}


//////////////////////////binary search with recursion\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

#include <iostream>
using namespace std;

int binarySearch(const int arr[], int item, int start, int end){
    if (start > end){
        return -1;
    }
    
    int mid = (start + end) / 2;
    
    if (arr[mid] == item) return mid;
    
    else if (arr[mid] < item)
        return binarySearch(arr, item, mid+1, end);
        
    else
        return binarySearch(arr, item, start, mid-1);
}

int main()
{    
    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int item = 3;
    int ans = binarySearch(arr, item, 0, n-1);
    
    cout << ans;
}
