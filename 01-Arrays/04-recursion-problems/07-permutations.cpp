//print all the permutations of a given integer array.


#include <print>
#include <iostream>
#include <vector>
using namespace std;

void permute(int arr[], vector<vector<int>>&ans, vector<int>&temp, vector<bool>&checked, int n){
    //base condition
    if (temp.size() == n){
        ans.push_back(temp);
        return;
    }
    
    for (int i = 0; i < n; i++){
        if (checked[i] == false){
            checked[i] = true;
            temp.push_back(arr[i]);
            
            permute(arr, ans, temp, checked, n);
            
            checked[i] = false;
            temp.pop_back();
        }
    }
}
int main()
{
    int arr[] = {1,2,3,4};
    vector<vector<int>>ans;
    vector<int>temp;
    vector<bool>checked(sizeof(arr)/sizeof(arr[0]), false);
    int n = sizeof(arr) / sizeof(arr[0]);
    
    permute(arr, ans, temp, checked, n);
    
    for (int i = 0; i < ans.size(); i++){
        for (int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
