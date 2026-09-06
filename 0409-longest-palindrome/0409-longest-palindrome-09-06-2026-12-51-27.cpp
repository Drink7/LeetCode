class Solution {
public:
    int longestPalindrome(string s) {
        // check if odd or even
        // even: all use (result += even)
        // odd: if odd >= 1, if odd not is used (result += odd)
        // if used, result += (2 * (odd/2))
        // TC: O(n), n is s length
        // SC: O(n) 
        unordered_map<char, int> dict;
        int result = 0;
        bool oddUsed = false;

        for (auto const& c : s) {
            dict[c]++;
        }

        for (auto [k, v] : dict) {
            if (v % 2 == 0) {
                result += v;
            } else {
                if (!oddUsed) {
                    result += v;
                    oddUsed = true;
                } else {
                    result += (2 * (v / 2));
                }
            }
        }
        return result;
    }
};