class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // shortest -> bfs
        // check endWord in the wordList or not
        // if not -> must be false, can not reach
        // if true, start to bfs search
        // TC: O(m * n), m words, word average length is n
        // SC: O(m * n)
        unordered_map<string, bool> visited;
        bool isValid = false;
        for (auto const& word : wordList) {
            if (word == endWord) {
                isValid = true;
            }
            visited[word] = false;
        }

        if (!isValid) {
            return 0;
        }

        queue<string> q;
        int cnt = 1; // beginWord
        q.push(beginWord);
        while (q.size() > 0) {
            int qSize = q.size();

            for (int i = 0; i < qSize; i++) {
                string word = q.front();
                q.pop();

                if (word == endWord) {
                    return cnt;
                }

                for (int j = 0; j < word.size(); j++) {
                    char tmp = word[j];
                    for (int k = 0; k < 26; k++) {
                        if (word[j] == 'a' + k) continue;
                        word[j] = 'a' + k;
                        if (visited.count(word) > 0 && !visited[word]) {
                            visited[word] = true;
                            q.push(word);
                        }
                    }
                    word[j] = tmp;
                }
            }
            cnt++;
        }
        return 0;
    }
};