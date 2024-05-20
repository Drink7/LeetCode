class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        // do not use trie
        // TC: O(n * m)
        // SC: O(1)
        int count = 0;
        for (int i = 0; i < words.size(); i++) {
            string base = words[i];
            for (int j = i + 1; j < words.size(); j++) {
                string prefix = base;
                string word = words[j];
                if (countHelper(prefix, word)) {
                    reverse(prefix.begin(), prefix.end());
                    reverse(word.begin(), word.end());
                    if (countHelper(prefix, word)) {
                        count++;
                    }
                }
            }
        }
        return count;
    }

    bool countHelper(string prefix, string word) {
        if (prefix.size() > word.size()) {
            return false;
        }

        for (int i = 0; i < prefix.size(); i++) {
            if (prefix[i] != word[i]) {
                return false;
            }
        }
        return true;
    }
};