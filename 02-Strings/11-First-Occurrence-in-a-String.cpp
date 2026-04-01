/*
 * Problem: 28. Find the Index of the First Occurrence in a String
 * Description: Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
*/

//bruteforce solution -
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(); 
        int m = needle.size();

        for (int i = 0; i <= n - m; i++){
            int first = i, sec = 0, temp = i;

            while (sec < m){
                if (haystack[first] == needle[sec]){
                    first ++ ; sec++;
                } else {
                     break;
                }
            }

            if (sec == m)
                return temp;
        }

        return -1;
    }
};
