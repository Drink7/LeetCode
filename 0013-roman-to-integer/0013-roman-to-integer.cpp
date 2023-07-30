class Solution {
public:
    int romanToInt(string s) {
        // Notice the 4, 9 cases
        int n = s.size();
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (i + 1 < n && dict[s[i + 1]] > dict[s[i]]) {
                result -= dict[s[i]];
            } else {
                result += dict[s[i]];
            }
        }
        return result;
    }
private:
    unordered_map<char, int> dict = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
};