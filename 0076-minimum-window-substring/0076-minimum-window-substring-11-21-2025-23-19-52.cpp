class Solution {
public:
    string minWindow(string s, string t) {
        // minimum window substring of s that every char in t is included
        // hash map store t char frequency
        // traverse s
        // record t count
        // char in t meet, t count --, move right until t count == 0
        // move left to find min window
        // record left and right - left + 1 -> size
        // min window == s.size() + 1 --> ""
        // else s.substr(left, min window)
        // TC: O(m + n)
        // SC: O(m + n)
        if (t.size() > s.size()) return "";

        unordered_map<char, int> dict;
        for (auto const& c : t) {
            dict[c]++;
        }

        int left = 0, right = 0;
        int n = s.size();
        int tCnt = t.size();
        int ansId = 0;
        int ansLen = n + 1;
        while (right < n) {
            if (dict[s[right]] > 0) {
                tCnt--;
            }
            dict[s[right]]--;

            // move left
            while (tCnt == 0) {
                if (right - left + 1 < ansLen) {
                    ansId = left;
                    ansLen = right - left + 1;
                }
                if (dict[s[left]] >= 0) {
                    tCnt++;
                }
                dict[s[left]]++;
                left++;
            }
            right++;
        }
        return ansLen == n + 1 ? "" : s.substr(ansId, ansLen);
    }
};