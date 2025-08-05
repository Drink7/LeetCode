class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // p store hash_map<char, int>
        // sliding window,
        // anagramCnt = p.size()
        // if map[right] > 0, anagramCnt--;
        // map[right]--;
        // if map[left] >= 0, anagramCnt++;
        // map[left]++;
        // TC: O(m + n)
        // SC: O(n)
        unordered_map<char, int> dict;
        vector<int> result;
        for (auto const& c : p) {
            dict[c]++;
        }

        int anagramCnt = p.size();
        int left = 0, right = 0;
        while (right < s.size()) {
            if (dict[s[right]] > 0) {
                anagramCnt--;
            }
            dict[s[right]]--;

            if (right - left + 1 == p.size()) {
                if (anagramCnt == 0) {
                    result.push_back(left);
                }

                if (dict[s[left]] >= 0) {
                    anagramCnt++;
                }
                dict[s[left]]++;
                left++;
            }
            right++;
        }
        return result;
    }
};