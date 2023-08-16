class Solution {
public:
    int characterReplacement(string s, int k) {
        // Sliding window
        // TC: O(n)
        // SC: O(1)
        // max char number + k >= current window size, it means we can replace all the distinct char in our window
        // else, it means we can not replace all the distinct char in the window
        // move left pointer
        int n = s.size();
        int left = 0;
        int right = 0;
        int result = 0;
        unordered_map<char, int> dict;
        while (right < n) {
            dict[s[right]]++;

            // right - left + 1 is our window size
            while (findMax(dict) + k < right - left + 1) {
                dict[s[left]]--;
                left++;
            }

            result = max(result, right - left + 1);
            right++;
        }
        return result;
    }

    int findMax(unordered_map<char, int>& dict) {
        int maxVal = INT_MIN;
        for (auto const& p : dict) {
            if (p.second > maxVal) {
                maxVal = p.second;
            }
        }
        return maxVal;
    }
};