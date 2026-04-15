//finds the sum of the all the subsets of the array contigious and non contigious


#include <vector>
#include <iostream>
using namespace std;

void mrSubset(int arr[], int &sum, vector<int>&temp, int index, int n){
    if (index == n){
        for (int i = 0; i < temp.size(); i++){
            sum = sum + temp[i];
        }
        return;
    }    
    
    mrSubset(arr, sum, temp, index + 1, n);
    temp.push_back(arr[index]);
    mrSubset(arr, sum, temp, index + 1, n);
    temp.pop_back();
}

int main()
{
    int arr[] = {1,2,3,4};
    int sum = 0;
    vector<int>temp;
    int index = 0;
    int n = sizeof(arr) / sizeof(arr[0]);
    
    mrSubset(arr, sum, temp, index, n);
    cout << sum;
    

    return 0;
}
