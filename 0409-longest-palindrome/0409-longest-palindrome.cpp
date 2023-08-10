class Solution {
public:
    int longestPalindrome(string s) {
        // Use hash table to add all even number of letter and maximum odd number of letter
        // TC: O(n)
        // SC: O(n) 
        unordered_map<char, int> dict;
        for (auto const& c : s) {
            dict[c]++;
        }

        int result = 0;
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