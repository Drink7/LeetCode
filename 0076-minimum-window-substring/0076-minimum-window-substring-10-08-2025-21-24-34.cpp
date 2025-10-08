class Solution {
public:
    string minWindow(string s, string t) {
        // substring
        // sliding window / dp
        // sliding window
        // left, freq hash map
        // count t size
        // left go until count = 0
        // move right and check min size
        // if count > 0, continue left go
        // TC: O(m + n), m is s.size(), n is t.size()
        // SC: O(n)
        if (t.size() > s.size()) {
            return "";
        }

        unordered_map<char, int> freqMap;
        int left = 0;
        int right = 0;
        int m = s.size(), n = t.size();
        int count = n;
        int windowStart = -1;
        int windowSize = m + 1;

        for (auto const& c : t) {
            freqMap[c]++;
        }

        while (right < m) {
            if (freqMap[s[right]] > 0) {
                count--;
            }
            freqMap[s[right]]--;

            while (count == 0) {
                if (right - left + 1 < windowSize) {
                    windowStart = left;
                    windowSize = right - left + 1;
                }

                // move left
                if (freqMap[s[left]] >= 0) {
                    count++;
                }
                freqMap[s[left]]++;
                left++;
            }
            right++;
        }

        if (windowStart == -1) {
            return "";
        }
        return s.substr(windowStart, windowSize);
    }
};