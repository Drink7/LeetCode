class Solution {
public:
    string minWindow(string s, string t) {
        // hash table + sliding window
        // TC: O(m * n)
        // SC: O(n)
        if (t.size() > s.size()) {
            return "";
        }

        int m = s.size();
        int n = t.size();
        int counter = n;
        int left = 0;
        int right = 0;
        int resultStart = 0;
        int resultLength = INT_MAX;
        unordered_map<char, int> dict;

        // store t freq
        for (auto const& c : t) {
            dict[c]++;
        }

        while (right < m) {
            if (dict[s[right]] > 0) {
                counter--;
            }
            dict[s[right]]--;

            if (right - left + 1 >= n) {
                while (counter == 0) {
                    if (resultLength > right - left + 1) {
                        resultLength = right - left + 1;
                        resultStart = left;
                    }

                    dict[s[left]]++;
                    if (dict[s[left]] > 0) {
                        counter++;
                    }
                    left++;
                }
            }
            right++;
        }
        return resultLength == INT_MAX ? "" : s.substr(resultStart, resultLength);
    }
};