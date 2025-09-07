class Solution {
public:
    int characterReplacement(string s, int k) {
        // sliding window
        // ABAB
        // right - left
        // TC: O(26 * n)
        // SC: O(1)
        int left = 0;
        int right = 0;
        int result = 0;
        int n = s.size();
        vector<int> letters(26, 0);
        while (right < n) {
            letters[s[right] - 'A']++;
            while (right - left + 1 - findMax(letters) > k) {
                letters[s[left] - 'A']--;
                left++;
            }
            result = max(result, right - left + 1);
            right++;
        }
        return result;
    }

    int findMax(vector<int>& letters) {
        int maxVal = -1;
        for (int i = 0; i < letters.size(); i++) {
            maxVal = max(maxVal, letters[i]);
        }
        return maxVal;
    }
};