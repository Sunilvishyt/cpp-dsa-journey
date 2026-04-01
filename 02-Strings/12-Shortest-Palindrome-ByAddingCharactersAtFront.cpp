/*
 * Problem: 214. Shortest Palindrome
 * Description: You are given a string s. You can convert s to a palindrome by adding characters in front of it.
Return the shortest palindrome you can find by performing this transformation.
 * Time Complexity: O(n)
 * Space Complexity: O(n)
*/

class Solution {
public:
    string shortestPalindrome(string s) {
        //create two copies of original string and reverse one of them.
        string reservedString = s;
        string temp = s;
        reverse(temp.begin(), temp.end());

        //add special character and reversed string to the reservedString.
        reservedString += '@';
        reservedString += temp;
        int n = reservedString.size();

        //create an lps array and calculate lps.
        vector<int>lps(n, 0);
        int pre = 0, suf = 1;

        while (suf < n ){
            if (reservedString[pre] == reservedString[suf]){
                lps[suf] = pre + 1;
                pre++; suf++;
            }

            else {
                if (pre == 0){
                    lps[suf] = 0;
                    suf++;
                }

                else {
                    pre = lps[pre - 1];
                }
            }
        }

        //get the substring that is not presented in the original string reverse it and add all into the ans variable.
        string ans = s.substr(lps[n-1]);
        reverse(ans.begin(), ans.end());

        ans += s;
        return ans;
    }
};
