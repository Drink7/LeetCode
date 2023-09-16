class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // hashmap
        // TC: O(m + n), m is ransomNote size, n is magazine size
        // SC: O(n)
        unordered_map<char, int> magazineDict;
        for (auto const& c : magazine) {
            magazineDict[c]++;
        }

        // traverse ransomNote
        for (auto const& c : ransomNote) {
            if (magazineDict[c] == 0) {
                return false;
            }
            magazineDict[c]--;
        }
        return true;
    }
};