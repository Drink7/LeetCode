class Solution {
public:
    int romanToInt(string s) {
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
    }
private:
    unordered_map<char, int> dict{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
};