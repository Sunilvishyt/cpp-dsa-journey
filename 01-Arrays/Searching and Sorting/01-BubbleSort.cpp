/*
 * Problem: Bubble Sort
 * Description: Sorts the Array by running multiple rounds/phases, optimized to not run if the array is already sorted after few rounds.
 * Time Complexity: O(n²)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
using namespace std;

void BubbleSort(vector<int>&arr){
    int n = arr.size();
    if (n <= 1) return ; 
    bool swapped = false;
    
    for (int i = n - 1; i > 0 ; i--){
        swapped = false;
        for (int j = 0; j < i; j++){
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

int main()
{
    vector<int>arr = {2,3,1,8,2,6,5,4};
    BubbleSort(arr);
    for (int k = 0; k < arr.size(); k++)
        cout << arr[k] << " ";
    return 0;
}

/*
Learning - using swapped variable help in finding the inner for loop sorted the data or not, if swapped variable is false them,
the inner loop didnt sorted anything which means -> array is already sorted
so, we dont have to run the rounds then we can break.
*/
