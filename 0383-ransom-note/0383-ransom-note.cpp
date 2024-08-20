class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // map store magazine
        // check ransomnote letter one by one
        // TC: O(n), n is ransomNote length
        // SC: O(m), m is magazine length
        unordered_map<char, int> wordDict;
        for (auto const& c : magazine) {
            wordDict[c]++;
        }

        // check ransomnote
        for (auto const& c : ransomNote) {
            if (wordDict[c] == 0) {
                return false;
            } else {
                wordDict[c]--;
            }
        }
        return true;
    }
};