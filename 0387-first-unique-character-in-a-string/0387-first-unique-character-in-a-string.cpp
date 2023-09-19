class Solution {
public:
    int firstUniqChar(string s) {
        // hash map
        unordered_map<char, int> letterMap;
        vector<int> letterIndex(26, INT_MAX);
        for (int i = 0; i < s.size(); i++) {
            if (letterMap.count(s[i]) < 1) {
                letterIndex[s[i] - 'a'] = i;
            }
            letterMap[s[i]]++;
        }

        int result = INT_MAX;
        for (auto const& p : letterMap) {
            char letter = p.first;
            int letterCnt = p.second;
            if (letterCnt == 1) {
                if (result > letterIndex[letter - 'a']) {
                    result = letterIndex[letter - 'a'];
                }
            }
        }
        return (result == INT_MAX) ? -1 : result;
    }
};