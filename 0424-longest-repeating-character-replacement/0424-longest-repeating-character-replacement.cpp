class Solution {
public:
    int characterReplacement(string s, int k) {
        // sliding window + count max
        // TC: O(n)
        // SC: O(1)
        vector<int> letters(26, 0);
        int left = 0;
        int right = 0;
        int n = s.length();
        int result = 0;
        while (right < n) {
            char rightChar = s[right];
            letters[rightChar - 'A']++;
            while ((right - left + 1) - findMax(letters) > k) {
                letters[s[left] - 'A']--;
                left++;
            }
            result = max(result, (right - left + 1));
            right++;
        }
        return result;
    }

    int findMax(vector<int>& arr) {
        int result = 0;
        for (auto const& num : arr) {
            if (num > result) {
                result = num;
            }
        }
        return result;
    }
};