class TrieNode {
public:
    unordered_map<char, TrieNode*> childMap;
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
        for (auto const& c : word) {
            if (cur->childMap.count(c) < 1) {
                cur->childMap[c] = new TrieNode();
            }
            cur = cur->childMap[c];
        }
        cur->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for (auto const& c : word) {
            if (cur->childMap.count(c) < 1) {
                return false;
            }
            cur = cur->childMap[c];
        }
        return cur->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (auto const& c : prefix) {
            if (cur->childMap.count(c) < 1) {
                return false;
            }
            cur = cur->childMap[c];
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