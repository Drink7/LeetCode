class Solution {
public:
    int romanToInt(string s) {
        /*
        // Traverse
        // TC: O(n)
        // SC: O(n)
        int val = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (i + 1 < n &&
                ((s[i] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X')) ||
                (s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C')) ||
                (s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M')))) {
                val += dict[s[i + 1]] - dict[s[i]];
                i++;
            } else {
                val += dict[s[i]];
            }
        }
        return val;
        */
        // Roman numerals are usually written largest to smallest from left to right
        // XII (7), XXVII (27), III (3)...
        // If a small value is placed before a bigger value then it's a combine number
        // IV (4), IX (9), XIV (14)
        // IV = -1 + 5
        // TC: O(n)
        // SC: O(n)
        int val = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (i < n - 1 && dict[s[i]] < dict[s[i + 1]]) {
                val -= dict[s[i]];
            } else {
                val += dict[s[i]];
            }
        }
        return val;
    }
private:
    unordered_map<char, int> dict{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
};