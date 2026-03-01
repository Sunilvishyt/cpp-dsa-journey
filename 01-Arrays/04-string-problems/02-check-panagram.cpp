/*
 * Problem: 1832. Check if the Sentence Is Pangram
 * Description: A pangram is a sentence where every letter of the English alphabet appears at least once.
                Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.
 * Time Complexity: O(n)
 * Space Complexity: O(1) //because the input size doesnt grows it remains constant so we dont call it O(26)
*/

class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int>arr(26,0);
        for (int i = 0; i < sentence.size(); i++){
            int ascii = sentence[i] - 'a';
            arr[ascii] = 1;
        }

        for (int i = 0; i < arr.size(); i++){
            if (arr[i] == 0){
                return false;
            }
        }
        return true;
    }
};
