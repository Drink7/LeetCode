class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // s2 size >= s1 is valid, else invalid
        // store s2 into a dict map
        // TC: O(m + n)
        // SC: O(m + n)
        int m = s1.size();
        int n = s2.size();
        if (m > n) {
            return false;
        }

        unordered_map<char, int> dict;
        for (auto const& c : s1) {
            dict[c]++;
        }

        int left = 0, right = 0;
        int cnt = m;

        while (right < n) {
            if (dict[s2[right]] > 0) {
                cnt--;
            }

            dict[s2[right]]--;
            if (right - left + 1 == m) {
                if (cnt == 0) {
                    return true;
                }

                if (dict[s2[left]] >= 0) {
                    cnt++;
                }
                dict[s2[left]]++;
                left++;
            }
            right++;
        }
        return false;
    }
};