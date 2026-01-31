/*
 * Problem: Selection Sort.
 * Description: Sorts the array by picking the smallest elemtent from the unsorted part and placing it in correct position.
 * Time Complexity: O(n²)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int>arr = {5,4,7,3,8,1,9,2,0};
    int n = arr.size();
    int key, temp;
    
    cout<< "Original Array : ";
    for (int k = 0; k < n ; k++)
    cout << arr[k] << " ";
    cout<< endl;
    
    for (int i = 0; i < n-1; i++){
        temp = i;
        for (int j = i + 1; j < n; j++){
            if (arr[temp] > arr[j]){
                temp = j;
            }
        }
        if (temp != i)
            swap(arr[i],arr[temp]);
    }
    
    cout<< "Sorted Array : ";
    for (int k = 0; k < n ; k++)
        cout<< arr[k] << " ";
        
    return 0;
}

/*
Learning - Selection sort is better than bubble sort because it performs one swap per 'ith' iteration.
*/