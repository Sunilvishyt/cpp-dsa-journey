/*
 * Problem: 13. Roman to Integer
 * Description: convert the roman numbers into string.
 * Time Complexity: O(n)
 * Space Complexity: O(1)
*/

class Solution {
public:
    int num(char c ) {
        if (c == 'I') return 1;
        if (c == 'V') return 5;
        if (c == 'X') return 10;
        if (c == 'L') return 50;
        if (c == 'C') return 100;
        if (c == 'D') return 500;
        if (c == 'M') return 1000;
        return 0;
    }

    int romanToInt(string s) {
        int sum = 0;
        int index = 0;
        while (index < s.size()-1){
            if (num(s[index]) < num(s[index + 1]))
                sum -= num(s[index]);
            else {
                sum += num(s[index]);
            }
            index++;
        }
        sum += num(s[index]);
        return sum;

    }
};
