class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // TC: O(m * n^2)
        // SC: O(m * n^2)
        bool isEndExist = false;
        for (int i = 0; i < wordList.size(); i++) {
            if (wordList[i] == endWord) {
                isEndExist = true;
            }
        }

        if (!isEndExist) {
            return 0;
        }

        unordered_set<string> dict;
        dict.insert(beginWord);
        for (auto const& word : wordList) {
            dict.insert(word);
        }


        queue<string> q;
        q.push(beginWord);
        int result = 1;
        while (q.size() > 0) {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                string cur = q.front();
                q.pop();

                if (cur == endWord) {
                    return result;
                }

                for (int i = 0; i < cur.size(); i++) {
                    char c = cur[i];
                    for (int j = 0; j < 26; j++) {
                        cur[i] = 'a' + j;
                        if (dict.count(cur) > 0) {
                            q.push(cur);
                            dict.erase(cur);
                        }
                        cur[i] = c;
                    }
                }
            }
            result++;
        }
        return 0;
    }

};