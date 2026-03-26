/*
 * Problem: 9. Palindrome Number
 * Description: Given an integer x, return true if x is a palindrome, and false otherwise.
 * Time Complexity: O(n)
 * Space Complexity: O(1)
*/

//using to_string();
class Solution {
public:
    bool isPalindrome(int x) {
        string num = to_string(x);
        int i = 0;
        int j = num.size() - 1;

        while (i < j){
            if (num[i] != num[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};

