class Solution {
public:
    int characterReplacement(string s, int k) {
        // Sliding window
        // TC: O(n)
        // SC: O(1)
        // max char number + k >= current window size, it means we can replace all the distinct char in our window
        // else, it means we can not replace all the distinct char in the window
        // move left pointer
        // TC: O(n)
        // SC: O(n)
        unordered_map<char, int> dict;
        int n = s.size();
        int left = 0;
        int right = 0;
        int maxLen = 0;
        while (right < n) {
            dict[s[right]]++;
            while (findMaxCnt(dict) + k < right - left + 1) {
                dict[s[left]]--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }

    int findMaxCnt(unordered_map<char, int>& dict) {
        int maxCnt = INT_MIN;
        for (auto const& p : dict) {
            maxCnt = max(maxCnt, p.second);
        }
        return maxCnt;
    }
};