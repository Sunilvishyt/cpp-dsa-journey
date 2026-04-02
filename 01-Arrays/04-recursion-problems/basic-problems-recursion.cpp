//////////////////printing array elements with recursion \\\\\\\\\\\\\\\\\

#include <iostream>
using namespace std;

void printer(int arr[], int n){
    if (n == -1) return ;
    printer(arr, n-1);
    cout << arr[n] << " ";
    return ;
    
}

int main()
{
    int arr[] = {1,2,3,4,5,6};
    printer(arr, sizeof(arr) / sizeof(arr[0])-1);
    return 0;
}


//////////////sum of arrays with recursion\\\\\\\\\\\\\\
#include <iostream>
using namespace std;

int sum (int arr[], int n){
    if (n == -1) return 0;
    
    return arr[n] + sum(arr, n-1);
    
}

int main()
{
    int arr[] = {1,2,3,4,5,6};
    cout << sum(arr, sizeof(arr) / sizeof(arr[0])-1);
    return 0;
}


/////////////minimum element in array with recursion\\\\\\\\\\\\\\\\\\\\\
#include <iostream>
using namespace std;

int minelement(int arr[], int n, int index){
    if (index == n-1) 
        return arr[index];
        
    return min(arr[index], minelement(arr, n, index +1));
}

int main()
{
    int arr[] = {1,2,3,4,-4,6};
    cout << minelement(arr, sizeof(arr) / sizeof(arr[0])-1, 0);
    return 0;
}


/*
note - just solve one case in case of recursion and other cases will be automatically handle by itself.
*/
