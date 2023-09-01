class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // TC: O(n * m^2), n is wordList length, m is the length of dequeued word
        // SC: O(n * m^2)
        bool isValid = false;
        for (auto const& word : wordList) {
            if (word == endWord) {
                isValid = true;
                break;
            }
        }

        if (!isValid) {
            return 0;
        }

        int result = 1;
        unordered_set<string> wordSet;
        wordSet.insert(beginWord);
        for (auto const& str : wordList) {
            wordSet.insert(str);
        }

        queue<string> q;
        q.push(beginWord);
        while (!q.empty()) {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                string cur = q.front();
                q.pop();
                cout << cur << endl;
                if (cur == endWord) {
                    return result;
                }

                for (int j = 0; j < cur.size(); j++) {
                    char c = cur[j];
                    for (int k = 0; k < 26; k++) {
                        cur[j] = k + 'a';
                        if (wordSet.count(cur)) {
                            // All the words in wordList are unique.
                            wordSet.erase(cur);
                            q.push(cur);
                        }
                    }
                    cur[j] = c;
                }
            }
            result++;
        }
        return 0;
    }
};