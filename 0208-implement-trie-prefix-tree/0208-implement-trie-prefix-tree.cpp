class TrieNode {
public:
    char val;
    unordered_map<char, TrieNode*> childMap;
    bool isWord = false;
    TrieNode() {
        val = ' ';
    }

    TrieNode(char in) {
        val = in;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (cur->childMap.count(c) < 1) {
                TrieNode* newChar = new TrieNode(c);
                cur->childMap[c] = newChar;
            }
            cur = cur->childMap[c];
        }
        cur->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (cur->childMap.count(c) < 1) {
                return false;
            }
            cur = cur->childMap[c];
        }

        if (cur->isWord) {
            return true;
        } else {
            return false;
        }
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (int i = 0; i < prefix.size(); i++) {
            char c = prefix[i];
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