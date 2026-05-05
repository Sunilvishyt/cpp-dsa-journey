/*
 * Problem: Valid Palindrome (LeetCode : 125)
 * Description: Given a string s, return true if it is a palindrome, or false otherwise.
 * Time Complexity: O(n)
 * Space Complexity: O(1)
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size()-1;

        while (start < end){
            //if character is not alphanumric we have to skip that.
            if (!isalnum(s[start])) start ++;
            else if (!isalnum(s[end])) end--;

            //check palindrome normally with lowering first.
            else {
                if (tolower(s[start]) != tolower(s[end])) return false;
                start++; end--;
            }
        }

        return true;
    }
};
