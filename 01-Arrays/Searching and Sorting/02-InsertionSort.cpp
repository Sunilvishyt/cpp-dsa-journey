/*
 * Problem: Insertion Sort
 * Description: Sorts the array elements by checking if the particular element is in the right place if not then it places in the correct position.
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
using namespace std;

void InsertionSort(vector<int>& arr, int n){
    if (n <= 1) return;
    
    for (int i = 1; i < n; i++){
        if (arr[i-1] > arr[i]){
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 and arr[j] > key){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
        }
    }
}

int main(){
    vector<int>arr = {2,3,4,9,8,1,1,1,1,1,32,32,4,9,8,6,7};
    int n = arr.size();

    InsertionSort(arr, n);
    for (int k = 0; k < arr.size(); k++)
        cout << arr[k] << " ";
    return 0;
}
