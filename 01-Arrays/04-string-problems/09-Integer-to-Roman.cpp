/*
 * Problem: 12. Integer to Roman
 * Description: convert the numbers into roman numbers string.
 * Time Complexity: O(n)
 * Space Complexity: O(n)
*/


class Solution {
public:
    string roman_ones(int item){
        if (item == 1) return "I";
        if (item == 2) return "II";
        if (item == 3) return "III";
        if (item == 4) return "IV";
        if (item == 5) return "V";
        if (item == 6) return "VI";
        if (item == 7) return "VII";
        if (item == 8) return "VIII";
        if (item == 9) return "IX";
        return "";
    }

    string roman_tens(int item){
        if (item == 10) return "X";
        if (item == 20) return "XX";
        if (item == 30) return "XXX";
        if (item == 40) return "XL";
        if (item == 50) return "L";
        if (item == 60) return "LX";
        if (item == 70) return "LXX";
        if (item == 80) return "LXXX";
        if (item == 90) return "XC";
        return "";
    }

    string roman_hundreds(int item){
        if (item == 100) return "C";
        if (item == 200) return "CC";
        if (item == 300) return "CCC";
        if (item == 400) return "CD";
        if (item == 500) return "D";
        if (item == 600) return "DC";
        if (item == 700) return "DCC";
        if (item == 800) return "DCCC";
        if (item == 900) return "CM";
        return "";
    }

    string roman_thousands(int item){
        if (item == 1000) return "M";
        if (item == 2000) return "MM";
        if (item == 3000) return "MMM";
        return "";
    }

    string intToRoman(int num) {
        int temp = num;
        vector<int>arr;
        int tempnum;
        string ans = "";
        int i = 1;

        while (temp != 0){
            tempnum = temp % 10;
            temp = temp / 10;
            tempnum *= i;
            arr.push_back(tempnum);
            i *= 10;
        }

        for (int i = arr.size() -1 ; i >= 0; i--){
            if (arr[i] >= 1000 ) {
                string s = roman_thousands(arr[i]);
                ans += s;
            }
            if (arr[i] >= 100 ) {
                string s = roman_hundreds(arr[i]);
                ans += s;
            }
            if (arr[i] >= 10 ) {
                string s = roman_tens(arr[i]);
                ans += s;
            }
            if (arr[i] >= 1 ) {
                string s = roman_ones(arr[i]);
                ans += s;
            }
        }
        return ans;
    }
};
