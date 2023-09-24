class Solution {
public:
    string minWindow(string s, string t) {
        // sliding window
        // store minimum then move left if the window include all letter in t 
        // TC: O(m * n)
        // SC: O(m + n)
        if (s.size() < t.size()) {
            return "";
        }

        unordered_map<char, int> tDict;

        // store t
        for (auto const& c : t) {
            tDict[c]++;
        }

        int left = 0;
        int right = 0;
        int n = s.size();
        int minStart = 0;
        int minLength = INT_MAX;
        int counter = t.size();
        while (right < n) {
            if (tDict[s[right]] > 0) {
                counter--;
            }
            tDict[s[right]]--;
            while (counter == 0) {
                if (minLength > right - left + 1) {
                    minLength = right - left + 1;
                    minStart = left;
                }
                tDict[s[left]]++;
                if (tDict[s[left]] > 0) {
                    counter++;
                }
                left++;
            }
            right++;
        }
        return minLength == INT_MAX ? "" : s.substr(minStart, minLength);
    }
};