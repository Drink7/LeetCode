class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        /*
        // split the sentences
        // check if prefix
        // TC: O(m * n * t), m is sentence length, n is average word length, t is searchWord length
        // SC: O(1)

        stringstream ss(sentence);
        vector<string> tokens;
        string token;
        while (ss >> token) {
            tokens.push_back(token);
        }

        for (int i = 0; i < tokens.size(); i++) {
            int left = 0;
            int right = 0;
            string word = tokens[i];
            while (left < word.size() &&
                right < searchWord.size() &&
                word[left] == searchWord[right]) {
                left++;
                right++;
            }
            if (right == searchWord.size()) {
                return i + 1;
            }
        }
        return -1;
        */
        // without split
        // TC: O(m * n ), m is sentence length, n is searchWord length
        // SC: O(1)
        int cnt = 0;
        for (int i = 0; i < sentence.size(); i++) {
            string word = "";
            while (i < sentence.size() && sentence[i] != ' ') {
                word += sentence[i];
                i++;
            }

            cnt++;
            int left = 0;
            int right = 0;
            while (left < word.size() &&
                right < searchWord.size() &&
                word[left] == searchWord[right]) {
                left++;
                right++;
            }

            if (right == searchWord.size()) {
                return cnt;
            }
        }
        return -1;
    }
};