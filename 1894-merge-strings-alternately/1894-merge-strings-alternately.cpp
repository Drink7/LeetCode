class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        // TC: O(m + n)
        // SC: O(1)
        int m = word1.size();
        int n = word2.size();
        int word1Id = 0;
        int word2Id = 0;
        string result = "";
        while (word1Id < m && word2Id < n) {
            if (word1Id > word2Id) {
                // append word2
                result += word2[word2Id++];
            } else {
                // append word1
                result += word1[word1Id++];
            }
        }

        if (word1Id < m) {
            for (int i = word1Id; i < m; i++) {
                result += word1[i];
            }
        }

        if (word2Id < n) {
            for (int i = word2Id; i < n; i++) {
                result += word2[i];
            }
        }
        return result;
    }
};