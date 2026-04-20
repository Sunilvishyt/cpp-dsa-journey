/*
 * Problem: 2078. Two Furthest Houses With Different Colors.
 * Description: There are n houses evenly lined up on the street, and each house is beautifully painted. You are given a 0-indexed integer array colors of length n, where colors[i] represents the color of the ith house.
Return the maximum distance between two houses with different colors.
The distance between the ith and jth houses is abs(i - j), where abs(x) is the absolute value of x.

 * Time Complexity: O(n^2) [brute force] , o(n) optimal
 * Space Complexity: O(1)
*/

//brute force
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int maxi = -1;
        for (int i = 0; i < colors.size(); i++){
            for (int j = i; j < colors.size(); j++){
                if (colors[j] != colors[i]){
                    maxi = max(maxi, j-i);
                }
            }
        }
        return maxi;
    }
};


//optimal solution o(n)
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int left = 0;
        int right = n - 1;

        while (colors[left] == colors[right]){
            right --;
        }
        int distance1 = right;

        right = n-1; // reset right 
        while(colors[left] == colors[right]){
            left ++;
        }

        int distance2 = (n-1) - left;

        return max(distance1, distance2);
    }
};
