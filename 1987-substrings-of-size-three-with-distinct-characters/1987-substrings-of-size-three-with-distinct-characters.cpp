class Solution {
public:
    int countGoodSubstrings(string s) {
        // Fixed sliding window
        // TC: O(n)
        // SC: O(1)
        int n = s.size();
        int left = 0;
        int right = 0;
        int result = 0;
        while (right < n) {
            if (right - left + 1 == 3) {
                if (isValid(s, left, right)) {
                    result++;
                }
                left++;
            }
            right++;
        }
        return result;
    }

    bool isValid(string& s, int left, int right) {
        unordered_set<char> charSet;
        for (int i = left; i <= right; i++) {
            charSet.insert(s[i]);
        }
        return charSet.size() == 3;
    }
};