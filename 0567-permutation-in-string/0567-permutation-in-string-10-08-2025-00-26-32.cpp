class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // s1 size > s2 size, false
        // s1.size <= s2.size()
        // store s1 into hash map
        // traverse s2, check s1 count = 0
        // if count == 0, must be permutation
        // until the end
        // TC: O(m + n)
        // SC: O(m + n)
        int m = s1.size();
        int n = s2.size();
        int count = m;
        unordered_map<char, int> dict;
        for (auto const& c : s1) {
            dict[c]++;
        }

        int left = 0;
        int right = 0;
        while (right < n) {
            if (dict[s2[right]] > 0) {
                count--;
            }
            dict[s2[right]]--;

            if (right - left + 1 >= m) {
                // start checking
                if (right - left + 1 == m && count == 0) {
                    return true;
                }

                // move left
                if (dict[s2[left]] >= 0) {
                    count++;
                }
                dict[s2[left]]++;
                left++;
            }
            right++;
        }
        return false;
    }
};