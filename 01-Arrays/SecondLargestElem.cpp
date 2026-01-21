/*
 * Problem: Second largest element in array.
 * Description: Find second largest element in an array return -1 if second largest doesnt exists.
 * Time Complexity: O(n)
 * Space Complexity: O(1)
*/
#include <iostream>
using namespace std;
int SecondLargest(int arr[],int n){
    if (n < 2){return -1;}
    int maxi = arr[0];
    int secondmaxi = -1; 
    for (int i = 1; i < n; i++ ){
        if (arr[i] > maxi){
            secondmaxi = maxi;
            maxi = arr[i];
        }
        else if (arr[i] > secondmaxi && arr[i] != maxi){
            secondmaxi = arr[i];
        }
    }
    return secondmaxi;
}

int main()
{
    // int arr[] = {2,3,4,7,5,4,1,9,13,6,8};
    int arr[] = {2,2};
    int n = size(arr);
    int ans = SecondLargest(arr, n);
    cout << "Second Largest element is : " << ans;
    return 0;
}
