/******************************************************************************
Question : valid paranthesis (LeetCode : 20) 
Description : Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
time complexity : O(n)
space complexity : O(n)
*******************************************************************************/

class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
         
         for (int i = 0; i < s.size(); i++){
            
            if (s[i] == '(' or s[i] == '[' or s[i] == '{'){
                st.push(s[i]);
            }

            else {
                if (st.empty()) return false;

                else if (s[i] == ')')
                    if (st.top() == '(')
                        st.pop();
                    else return false;
                    
                else if (s[i] == ']')
                    if (st.top() == '[')
                        st.pop();
                    else return false;
                
                else {
                    if (st.top() == '{')
                        st.pop();
                    else return false;
                }
            }

         }
            return st.empty();
    }
};
