class TrieNode {
public:
    char c = '\0';
    bool isWord = false;
    unordered_map<char, TrieNode*> childMap;

    TrieNode() {
    }

    TrieNode(char in) {
        c = in;
    }
};

class Trie {
public:
    Trie() {
        // TC: O(m) -> insert/search
        // SC: O(m) -> insert
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for (auto const& c : word) {
            // not exist
            if (cur->childMap.count(c) < 1) {
                TrieNode* node = new TrieNode(c);
                cur->childMap[c] = node;
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