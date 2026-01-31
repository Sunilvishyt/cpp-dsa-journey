/*
 * Problem: Divide the array two parts with equal sums.
 * Description: If the array can we divided into two equal parts which have equal sum then it returns 1, else -1.
 * Time Complexity: O(n)
 * Space Complexity: O(1)
*/

#include <vector>
#include <iostream>
using namespace std;

int Checker(vector<int>& arr){
    int n = arr.size();
    if (n < 2) return -1;
    int total = 0;
    int prefix = 0;
    int ans = 0;
    for (int i = 0; i < n; i++){
        total += arr[i];
    }
    
    for (int i = 0; i < n; i++){
        prefix += arr[i];
        ans = total - prefix;
        if (ans == prefix){
            return 1;
        }
    }
    return -1;
}

int main()
{
    vector<int>arr = {3,4,-2,5,8,20,-10,8};
    int ans = Checker(arr);
    cout<<ans;
    return 0;
}
