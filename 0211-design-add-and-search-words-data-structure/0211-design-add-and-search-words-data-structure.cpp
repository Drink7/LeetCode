class WordNode {
public:
    unordered_map<char, WordNode*> dict;
    bool isWord = false;
    char val = ' ';
    WordNode() {
    }

    WordNode(char c) {
        val = c;
    }
};

class WordDictionary {
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
        return searchHelper(root, 0, word);
    }

    bool searchHelper(WordNode* root, int id, string& word) {
        WordNode* cur = root;
        for (int i = id; i < word.size(); i++) {
            if (word[i] == '.') {
                for (auto const& p : cur->dict) {
                    if(searchHelper(p.second, i + 1, word)) {
                        return true;
                    }
                }
                return false;
            } else {
                if (cur->dict.count(word[i]) < 1) {
                    return false;
                }
                cur = cur->dict[word[i]];
            }
        }
        return cur->isWord;
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