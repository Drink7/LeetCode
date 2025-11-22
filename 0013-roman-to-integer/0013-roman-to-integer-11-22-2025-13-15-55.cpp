class Solution {
public:
    int romanToInt(string s) {
        // check from right to left
        // when s[i] < s[i + 1], s[i] is negative
        // TC: O(n)
        // SC: O(1)
        int result = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            int romanInt = dict[s[i]];
            if (i < s.size() - 1 && dict[s[i]] < dict[s[i + 1]]) {
                romanInt = -romanInt;
            }
            result += romanInt;
        }
        return result;
    }
private:
    unordered_map<char, int> dict = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };
};