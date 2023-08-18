class Solution {
public:
    string minWindow(string s, string t) {
        // Sliding window
        // TC: O(m + n), m is s length, n is t length
        // SC: O(n)
        if (s.size() < t.size()) {
            return "";
        }

        unordered_map<char, int> tDict;
        for (auto const& c : t) {
            tDict[c]++;
        }

        int left = 0;
        int right = 0;
        int minStart = 0;
        int minLen = INT_MAX;
        int counter = t.size();

        while (right < s.size()) {
            char rightChar = s[right];
            if (tDict[rightChar] > 0) {
                counter--;
            }
            tDict[rightChar]--;

            // Move left
            while (counter == 0) {
                char leftChar = s[left];
                if (right - left + 1 < minLen) {
                    minStart = left;
                    minLen = right - left + 1;
                }
                tDict[leftChar]++;
                if (tDict[leftChar] > 0) {
                    counter++;
                }
                left++;
            }

            // Move right
            right++;
        }

        return (minLen == INT_MAX) ? "" : s.substr(minStart, minLen);
    }
};