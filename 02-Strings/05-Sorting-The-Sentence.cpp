/*
 * Problem: 1859. Sorting the Sentence
 * Description: A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each word consists of lowercase and uppercase English letters.
A sentence can be shuffled by appending the 1-indexed word position to each word then rearranging the words in the sentence.
For example, the sentence "This is a sentence" can be shuffled as "sentence4 a3 is2 This1" or "is2 sentence4 This1 a3".
Given a shuffled sentence s containing no more than 9 words, reconstruct and return the original sentence.

 * Time Complexity: O(n)
 * Space Complexity: O(1) //because the input size doesnt grows it remains constant so we dont call it O(26)
*/

class Solution {
public:
    string sortSentence(string s) {
        s += ' ';
        vector<string>ans(10,"");
        string temp;
        int index;
        int count = 0;

        for (index = 0; index < s.size(); index++){
            if (s[index] == ' '){
                int pos = temp[temp.size()-1] - '0';
                temp.pop_back();
                ans[pos] = temp;
                temp = "";
                count ++;
            }
            else {
                temp += s[index];
            }
        }
        for (int i = 1; i <= count; i++){
            temp += ans[i];
            temp += " ";
        }
        temp.pop_back();
        return temp;
    }
};
