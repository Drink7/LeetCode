class Solution {
public:
    string minWindow(string s, string t) {
        // sliding window, duplicates included
        // right keep going
        // left go if ABC all meet
        // min right - left + 1
        // also memo the valid cnt
        // if s[right] in t (> 0), valid cnt--
        // if s[left] in t (>= 0), valid cnt++
        // TC: O(m + n)
        // SC: O(n)
        unordered_map<char, int> dictT;
        for (auto const& c : t) {
            dictT[c]++;
        }

        int validCnt = t.size();
        int m = s.size();
        int left = 0, right = 0;
        int subStrId = 0;
        int subStrLen = INT_MAX;
        while (right < m) {
            if (dictT[s[right]] > 0) {
                validCnt--;
            }
            dictT[s[right]]--;
            while (validCnt == 0) {
                if (subStrLen > right - left + 1) {
                    subStrId = left;
                    subStrLen = right - left + 1;
                }

                if (dictT[s[left]] >= 0) {
                    validCnt++;
                }
                dictT[s[left]]++;
                left++;
            }
            right++;
        }
        return subStrLen == INT_MAX ? "" : s.substr(subStrId, subStrLen);
    }
};