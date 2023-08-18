class Solution {
public:
    string minWindow(string s, string t) {
        // two pointer with hash table (unordered_map)
        // TC: O(mn)
        // SC: O(mn)
        if (s.size() < t.size()) {
            return "";
        }

        unordered_map<char, int> dict;
        for (auto const& c : t) {
            dict[c]++;
        }

        int left = 0;
        int right = 0;
        int n = s.size();
        int minLen = INT_MAX;
        int minLeft = 0;
        int counter = t.size();
        while (right < n) {
            if (dict[s[right]] > 0) {
                counter--;
            }
            dict[s[right]]--;

            // Move left
            while (left <= right && counter == 0) {
                if (minLen > right - left + 1) {
                    minLen = right - left + 1;
                    minLeft = left;
                }
                dict[s[left]]++;
                if (dict[s[left]] > 0) {
                    counter++;
                }
                left++;
            }

            // move right
            right++;
        }
        return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
    }
};