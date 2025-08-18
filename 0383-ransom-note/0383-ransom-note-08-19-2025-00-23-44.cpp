class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // unordere_map
        // TC: O(m + n)
        // SC: O(n)
        unordered_map<char, int> dict;
        for (auto const& c : magazine) {
            dict[c]++;
        }

        for (auto const& c : ransomNote) {
            if (dict[c] <= 0) {
                return false;
            }
            dict[c]--;
        }
        return true;
    }
};