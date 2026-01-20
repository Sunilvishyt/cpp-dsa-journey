/*
 * Problem: Reverse array.
 * Description: Reversing the array using two pointers.
 * Time Complexity: O(n)
 * Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i = 0, j = n-1;
    
    //printing the array original array
    cout << "Original array : ";
    for (int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout<<endl;
    
    //reversing the array
    while(i < j){
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
    
    //printing the array reversed array
    cout<< "Reversed array : ";
    for (int i = 0; i < n ; i++)
        cout<< arr[i] << " ";
    return 0;
}

/*
Learning: we should use sizeof() to calculate the size of a raw array
it return the overall size of the array as int takes 4 bytes so it will return 
number of elements * 4 so we have to divide it will size of int to get the total number of elements in the array,

size() function is good but it will not work when we pass the array to another function
it will be affected with array decay,

we are touching every array in the array also because of this we can say
the time Complexity is O(n) and not O(logn).
*/