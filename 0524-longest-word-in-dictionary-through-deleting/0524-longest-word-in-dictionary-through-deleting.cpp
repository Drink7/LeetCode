class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        // sort dictionary
        // TC: O(m*n + nlogn) dictionary has n string, average length m
        // SC: O(1)
        sort(dictionary.begin(), dictionary.end(), [](string& s1, string& s2) {
            return s1 < s2;
        });
        string result = "";
        int longestLen = INT_MIN;
        int n = dictionary.size();
        for (int i = 0; i < n; i++) {
            int wordId = 0;
            string word = dictionary[i];
            for (int j = 0; j < s.size(); j++) {
                if (s[j] == word[wordId]) {
                    wordId++;
                }
            }
            if (wordId == word.size() && wordId > longestLen) {
                longestLen = wordId;
                result = word;
            }
        }
        return result;
    }
};