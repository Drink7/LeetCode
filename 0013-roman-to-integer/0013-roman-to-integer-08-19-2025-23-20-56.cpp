class Solution {
public:
    int romanToInt(string s) {
        // s must be a valid roman numeral
        unordered_map<char, int> symbolDict;
        unordered_map<string, int> subDict;
        symbolDict['I'] = 1;
        symbolDict['V'] = 5;
        symbolDict['X'] = 10;
        symbolDict['L'] = 50;
        symbolDict['C'] = 100;
        symbolDict['D'] = 500;
        symbolDict['M'] = 1000;
        // s[left] must larger than s[right]
        int n = s.size();
        if (n < 2) {
            return symbolDict[s[0]];
        } else {
            int result = 0;
            for (int i = 0; i < n; i++) {
                if (i < n - 1 && symbolDict[s[i]] < symbolDict[s[i + 1]]) {
                    // invalid
                    result -= symbolDict[s[i]];
                } else {
                    result += symbolDict[s[i]];
                }
            }
            return result;
        }
    }
};