class WordDictionary {
    // Trie
    // TC: O(n)
    // SC: O(n)
    class WordNode {
        public:
            char c;
            bool isWord = false;
            unordered_map<char, WordNode*> dict;
            WordNode() {
            }

            WordNode(char in) {
                c = in;
            }
    };
public:
    WordDictionary() {
        root = new WordNode();
    }
    
    void addWord(string word) {
        WordNode* cur = root;
        for (auto const& c : word) {
            if (cur->dict.count(c) < 1) {
                cur->dict[c] = new WordNode(c);
            }
            cur = cur->dict[c];
        }
        cur->isWord = true;
    }
    
    bool search(string word) {
        WordNode* cur = root;
        return searchHelper(cur, word, 0);
    }

    bool searchHelper(WordNode* node, string word, int start) {
        // backtracking
        for (int i = start; i < word.size(); i++) {
            char c = word[i];
            if (c == '.') {
                for (auto const& p : node->dict) {
                    if (searchHelper(p.second, word, i + 1)) {
                        return true;
                    }
                }
                return false;
            } else {
                if (node->dict.count(c) < 1) {
                    return false;
                }
                node = node->dict[c];
            }
        }
        if (node->isWord) {
            return true;
        } else {
            return false;
        }
    }

private:
    WordNode* root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */