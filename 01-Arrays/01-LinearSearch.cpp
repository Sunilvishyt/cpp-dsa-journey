/*
 * Problem: Linear Search
 * Description: Finding an element in an array by checking one by one.
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include<iostream>
using namespace std;

int LinearSearch(int array[], int size, int target){
    for (int i = 0; i < size; i++){
        if (array[i] == target) return i;
    }
    return -1;
}

int main(){
    int array_size;
    cout << "Enter array size :" << endl;
    cin >> array_size;
    if (array_size <= 0 ) throw runtime_error("invalid input, Enter correct Array size!");
    
    int array[array_size];
    for (int i = 0; i < array_size; i++){
        cout << "Enter element of array index = "<< i << endl;
        cin >> array[i];  
    }
    
    int target;
    cout << "Enter the target - " << endl;
    cin >> target;
    
    int result = LinearSearch(array, array_size, target);
    cout << "The index is : " << result;
    return 0;
}

/*
Learning - when we pass the array to other function it doesnt have metadata
like size etc because it gets passed as reference (pointer) so we can just
traverse it (while using raw array, thats not the case with vector).
so we have to send the computed size of the array to the function too if 
we want the array size to be known in the function too..
*/