/*
 * Problem: 409. Longest Palindrome
 * Description: Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
                Letters are case sensitive, for example, "Aa" is not considered a palindrome.
 * Time Complexity: O(n)
 * Space Complexity: O(1) //because the input size doesnt grows it remains constant so we dont call it O(26)
*/


class Solution {
public:
    int longestPalindrome(string s) {
        vector<int>lower(26,0);
        vector<int>upper(26,0);

        for (int i = 0; i < s.size(); i++){
            if (s[i] >= 'a'){
                lower[s[i] - 'a']++;
            }
            else {
                upper[s[i] - 'A']++;
            }
        }

        int count = 0;
        int odd = 0;

        for (int i = 0; i < 26; i++){
            if (lower[i] % 2 == 0){
                count += lower[i];
            } else {
                count += lower[i]-1;
                odd = 1;
            }
            if (upper[i] % 2==0){
                count += upper[i];
            } else {
                count += upper[i]-1;
                odd = 1;
            }
        }
        count += odd;
        return count;
    }
};
