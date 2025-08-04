class Solution {
public:
    int longestPalindrome(string s) {
        // use hash table to record the letter
        // use only one odd, others would use number odd-1
        // TC: O(n)
        // SC: O(n)
        unordered_map<char, int> dict;
        int result = 0;
        for (auto const& c : s) {
            dict[c]++;
        }

        bool isOddUsed = false; 
        for (auto const& p : dict) {
            if (p.second % 2 == 0) {
                result += p.second;
            } else {
                if (!isOddUsed) {
                    result += p.second;
                    isOddUsed = true;
                } else {
                    result += p.second - 1;
                }
            }
        }
        return result;
    }
};