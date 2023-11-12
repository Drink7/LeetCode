class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // store s2 into map, and count s1
        // fixed sliding window size (s1.size)
        // TC: O(mn)
        // SC: (m)
        if (s1.size() > s2.size()) {
            return false;
        }
        int m = s1.size();
        int n = s2.size();
        int left = 0;
        int right = 0;
        int counter = m;
        unordered_map<char, int> dict;

        // store s1 freq
        for (auto const& c : s1) {
            dict[c]++;
        }

        while (right < n) {
            if (dict[s2[right]] > 0) {
                counter--;
            }

            dict[s2[right]]--;

            if (right - left + 1 >= m) {
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