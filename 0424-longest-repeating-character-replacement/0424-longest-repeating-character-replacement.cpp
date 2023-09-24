class Solution {
public:
    int characterReplacement(string s, int k) {
        // vector to store letter count
        // string.size() > max letter cnt + k
        // need to move left
        // or continue moving right
        // TC: O(n)
        // SC: O(n)
        vector<int> letterArr(26, 0);
        int left = 0;
        int right = 0;
        int n = s.size();
        int result = 0;
        while (right < n) {
            char rightChar = s[right];
            letterArr[rightChar - 'A']++;

            // left move condition
            while (left < right && right - left + 1 > k + findMax(letterArr)) {
                letterArr[s[left] - 'A']--;
                left++;
            }
            result = max(result, right - left + 1);
            right++;
        }
        return result;
    }

    int findMax(vector<int>& nums) {
        int result = 0;
        for (auto const& num : nums) {
            if (num > result) {
                result = num;
            }
        }
        return result;
    }
};