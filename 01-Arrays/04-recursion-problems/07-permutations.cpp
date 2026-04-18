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


// ///////////////////////////optimized version/////////////////////////////
//using least space as possible


#include <print>
#include <iostream>
#include <vector>
using namespace std;

void permute(vector<int>&arr, vector<vector<int>>&ans, int index){
  //base condition
  if (index == arr.size()){
    ans.push_back(arr);
    return;
  }
  
  for (int i = index; i < arr.size(); i++){
    swap(arr[i], arr[index]);

    permute(arr, ans, index+1);

    swap(arr[i], arr[index]);

  }
}

int main()
{
    vector<int>arr = {1,2,3};
    vector<vector<int>>ans;
    int index = 0;
    
    permute(arr, ans, index);
    
    for (int i = 0; i < ans.size(); i++){
        for (int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

