class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // hash table for visited
        // BFS
        // TC: O(m * n) m words, each average n length
        // SC: O(m * n)
        unordered_set<string> availble;
        queue<string> q;

        // check first
        bool hasEnd = false;
        for (auto const& word : wordList) {
            if (word == endWord) {
                hasEnd = true;
            }
            availble.insert(word);
        }

        if (!hasEnd) {
            return 0;
        }

        int result = 1;
        q.push(beginWord);
        while (q.size() > 0) {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                string word = q.front();
                q.pop();

                if (word == endWord) {
                    return result;
                }

                for (int j = 0; j < word.size(); j++) {
                    string nextWord = word;
                    for (int k = 0; k < 26; k++) {
                        nextWord[j] = 'a' + k;
                        if (availble.count(nextWord) > 0) {
                            q.push(nextWord);
                            availble.erase(nextWord);
                        }
                    }
                }
            }
            result++;
        }
        return 0;
    }
};