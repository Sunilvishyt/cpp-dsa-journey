/*
 * Problem: sort string.
 * Description: Given a string consisting of lowercase letters, arrange all its letters in ascending order. 
 * Time Complexity: O(n)
 * Space Complexity: O(m)
*/

//geeks for geeks solution.

string sort(string s) {
    vector<int>arr(26,0);
    string ans;
    
    for (int i = 0; i < s.size(); i++){
        arr[s[i] - 'a']++;
    }
    
    for (int i = 0; i < arr.size(); i++){
        char c = i + 'a';
        while (arr[i]){
            ans += c;
            arr[i]--;
        }
    }
    
    return ans;
    
    
}
