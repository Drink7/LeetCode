class Solution {
public:
    int romanToInt(string s) {
        // traverse from back
        // if next one smaller then cur, use minus
        // else use plus
        // TC: O(n)
        // SC: O(n)
        int n = s.size();
        int result = dict[s[n - 1]];
        for (int i = n - 2; i >= 0; i--) {
            int cur = dict[s[i]];
            int prev = dict[s[i + 1]];
            if (cur < prev) {
                cur = -cur;
            }
            result += cur;
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
        {'M', 1000}
    };
};