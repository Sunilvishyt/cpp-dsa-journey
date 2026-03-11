/*
 * Problem: 1392. Longest Happy Prefix
 * Description: A string is called a happy prefix if is a non-empty prefix which is also a suffix (excluding itself).
    Given a string s, return the longest happy prefix of s. Return an empty string "" if no such prefix exists.
 * Time Complexity: O(n)
 * Space Complexity: O(n)
*/

//solution using KMP algorithm.
class Solution {
public:
    string longestPrefix(string s) {
        vector<int>arr(s.size(), 0);
        int pre = 0, suf = 1;
        int n = s.size();

        while (suf < n){
            if (s[pre] == s[suf]){
                arr[suf] = pre + 1;
                pre++; suf++;
            }

            else {
                if (pre == 0){
                    arr[suf] = 0;
                    suf++;
                }
                else {
                    pre = arr[pre -1];
                }
            }
        }
        int longestLen = arr[n - 1];
        return s.substr(0, longestLen);
    }
};
