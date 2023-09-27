class Trie {

    class TrieNode {
        public:
            bool isWord = false;
            char c;
            unordered_map<char, TrieNode*> dict;
            TrieNode() {
            }

            TrieNode(char val) {
                c = val;
            }
    };

public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for (auto const& c : word) {
            if (cur->dict.count(c) < 1) {
                cur->dict[c] = new TrieNode(c);
            }
            cur = cur->dict[c];
        }
        cur->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for (auto const& c : word) {
            if (cur->dict.count(c) < 1) {
                return false;
            }
            cur = cur->dict[c];
        }
        if (cur->isWord) {
            return true;
        } else {
            return false;
        }
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (auto const& c : prefix) {
            if (cur->dict.count(c) < 1) {
                return false;
            }
            cur = cur->dict[c];
        }
        return true;
    }
private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */