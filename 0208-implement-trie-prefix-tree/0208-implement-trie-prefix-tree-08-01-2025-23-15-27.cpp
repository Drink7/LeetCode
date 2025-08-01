class TrieNode {
public:
    TrieNode* childArr[26] = {nullptr};
    bool isWord = false;
    TrieNode() {
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (cur->childArr[c - 'a'] == nullptr) {
                TrieNode* node = new TrieNode();
                cur->childArr[c - 'a'] = node;
            }
            cur = cur->childArr[c - 'a'];
        }
        cur->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (cur->childArr[c - 'a'] == nullptr) {
                return false;
            }
            cur = cur->childArr[c - 'a'];
        }
        return cur->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (char c : prefix) {
            if (cur->childArr[c - 'a'] == nullptr) {
                return false;
            }
            cur = cur->childArr[c - 'a'];
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