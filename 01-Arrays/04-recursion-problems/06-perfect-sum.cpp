//print all the subsets which results in the target given. 

#include <print>
#include <iostream>
#include <vector>
using namespace std;

void targetSubset(int arr[], vector<vector<int>>&ans, vector<int>&temp, int index, int n, int target){
    //base condition.
    if (index == n){
        int sum = 0;
        for (int i = 0; i < temp.size(); i++){
            sum += temp[i];
        }
        if (sum == target){
            ans.push_back(temp);
        }
        return;
    }
    
    //not considering the value of array at particular index
    targetSubset(arr, ans, temp, index + 1, n, target);
    
    //considering the value of array at particular index
    temp.push_back(arr[index]);
    targetSubset(arr, ans, temp, index +1 , n, target);
    temp.pop_back();
}

int main()
{
    int arr[] = {1,2,3,4};
    int target = 5;
    vector<vector<int>>ans;
    vector<int>temp;
    
    int index = 0;
    int n = sizeof(arr) / sizeof(arr[0]);
    
    targetSubset(arr, ans, temp, index, n, target);
    
    //printing the ans arrays we got.
    for (int i = 0; i < ans.size(); i++){
        cout << "{ ";
        for (int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << "}";
        cout << endl;
    }

    return 0;
}
