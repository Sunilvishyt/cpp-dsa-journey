/*
 * Problem: 415. Add Strings

 * Description: Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.
      You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.
    
 * Time Complexity: O(n)
 * Space Complexity: O(n) //because using extra string for storing ans.
*/


class Solution {
public:
    //create a function so we can control that num1 will always be the largest in terms of size.
    string addfn(string num1, string num2){
        int firstidx = num1.size() -1; //handle num1
        int secidx = num2.size() -1;  //handle num2
        int carry = 0;
        string ans = "";
        
        //add all numbers from num2.
        while ( secidx >= 0 ){
            int sum = (num1[firstidx] - '0') + (num2[secidx] - '0') + carry;
            carry = sum / 10;
            char c = '0' + sum % 10;
            ans += c;
            firstidx--; secidx--;
        }

        //add the numbers that were remain in num1 to the ans and also add carry in them.
        while ( firstidx >= 0 ) {
            int sum = (num1[firstidx] - '0') + carry;
            carry = sum / 10;
            char c = '0' + sum % 10;
            ans += c;
            firstidx--;
        }

        //if carry still remain at last so we have to add it to the ans.
        if (carry > 0)
            ans += (carry + '0');
        
        reverse(ans.begin(), ans.end());
        return ans;
    }

    string addStrings(string num1, string num2) {
        //send in the form where num1 if always the largest one.
        if (num1.size() >= num2.size())
            return addfn(num1,num2);

        else return addfn(num2, num1);

    }
};
