/*
 * Problem: 2785. Sort Vowels in a String

 * Description: Given a 0-indexed string s, permute s to get a new string t such that:
      > All consonants remain in their original places. More formally, if there is an index i with 0 <= i < s.length such that s[i] is a consonant, then t[i] = s[i].
      > The vowels must be sorted in the nondecreasing order of their ASCII values. More formally, for pairs of indices i, j with 0 <= i < j < s.length such that s[i] and s[j] are vowels, then t[i] must not have a higher ASCII value than t[j].
        Return the resulting string.
    The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in lowercase or uppercase. Consonants comprise all letters that are not vowels.
    
 * Time Complexity: O(n)
 * Space Complexity: O(1) //because the input size doesnt grows it remains constant so we dont call it O(26)
*/

class Solution {
public:
    string sortVowels(string s) {
        vector<int>lower(26);
        vector<int>upper(26);

        for (int i = 0; i < s.size(); i++){
            if (s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u'){
                lower[s[i] - 'a']++;
                s[i] = '#';
            }
            else if (s[i] == 'A' or s[i] == 'E' or s[i] == 'I' or s[i] == 'O' or s[i] == 'U'){
                upper[s[i] - 'A']++;
                s[i] = '#';
            }
        }

        string allvowels = "";
        for (int i = 0; i < 26; i++){
            while (upper[i]){
                char c = i + 'A';
                allvowels += c;
                upper[i]--;
            }
        }

        for (int i = 0; i < 26; i++){
            while (lower[i]){
                char c = i + 'a';
                allvowels += c;
                lower[i]--;
            }
        }
        //now we have sorted vowels. 

        //inserting the vowels in the real string.
        int j = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '#'){
                s[i] = allvowels[j];
                j++;
            }
        }

        return s;
    }
};
