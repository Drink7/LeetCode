class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // Similar to 76. Minimum Window Substring
        // fixed size sliding window
        // TC: O(mn)
        // SC: O(n)
        if (s1.size() > s2.size()) {
            return false;
        }

        unordered_map<char, int> dict;
        for (auto const& c : s1) {
            dict[c]++;
        }

        int left = 0;
        int right = 0;
        int n = s2.size();
        int counter = s1.size();
        while (right < n) {
            if (dict[s2[right]] > 0) {
                counter--;
            }
            dict[s2[right]]--;

            if (right >= s1.size() - 1) {
                if (counter == 0) {
                    return true;
                } else {
                    dict[s2[left]]++;
                    if (dict[s2[left]] > 0) {
                        counter++;
                    }
                    left++;
                }
            }
            right++;
        }
        return false;
    }
};