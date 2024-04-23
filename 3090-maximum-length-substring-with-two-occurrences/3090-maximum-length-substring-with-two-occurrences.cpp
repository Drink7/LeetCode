class Solution {
public:
    int maximumLengthSubstring(string s) {
        // find maximum sliding window length
        // use a unordered_map to store
        // TC: O(n)
        // SC: O(n)
        int left = 0;
        int right = 0;
        int n = s.size();
        int result = 0;
        unordered_map<char, int> dict;
        while (right < n) {
            dict[s[right]]++;
            while (dict[s[right]] > 2) {
                dict[s[left]]--;
                left++;
            }
            result = max(result, right - left + 1);
            right++;
        }
        return result;
    }
};