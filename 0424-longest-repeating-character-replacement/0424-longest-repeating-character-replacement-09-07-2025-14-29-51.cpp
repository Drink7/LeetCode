class Solution {
public:
    int characterReplacement(string s, int k) {
        // hash table store <char, int> char, count
        // only record maxFreq of s[right], don't need to calculate max freq each move
        // left will move if right - left + 1 - maxFreq > k
        // result = max(result, right - left + 1);
        // TC: O(n)
        // SC: O(n)
        int left = 0, right = 0;
        unordered_map<char, int> dict;
        int n = s.size();
        int result = 0;
        int maxFreq = 0;
        while (right < n) {
            dict[s[right]]++;
            maxFreq = max(maxFreq, dict[s[right]]);
            while (right - left + 1 - maxFreq > k) {
                dict[s[left]]--;
                left++;
            }
            result = max(result, right - left + 1);
            right++;
        }
        return result;
    }
};