/*
 * Problem: Longest Substring Without Repeating Characters.
 * Description: Given a string s, find the length of the longest substring without duplicate characters.
            A substring is a contiguous sequence of characters within a string.
            
 * Time Complexity: O(n)
 * Space Complexity: O(m) // m is the number of unique characters in the string.
*/



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n < 1) return 0;

        int maxsize = 0;
        unordered_set<char>us;
        int left = 0, right = 0;

        while (right < n){
            if (! us.count(s[right])){
                us.insert(s[right]);
            }
            else {

                while (s[left] != s[right]){
                    us.erase(s[left]);
                    left++;
                }
                us.erase(s[left]);
                left++;
                us.insert(s[right]);
            }
            maxsize = max(maxsize,(int) us.size());
            right++;
        }
        return maxsize;
    }
};
