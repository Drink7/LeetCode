class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // use 26 char array to store magazine's character
        // traverse ransomNote
        // if magazine[char] == 0, return false
        // traverse all char,m return true
        // TC: O(m + n), m is ransomNote string length, n is magazine string length
        // SC: O(n)
        int arr[26] = {0};
        for (auto c : magazine) {
            arr[c - 'a']++;
        }

        for (auto c : ransomNote) {
            int idx = c - 'a';
            if (arr[idx] == 0) {
                return false;
            }
            arr[idx]--;
        }
        return true;
    }
};