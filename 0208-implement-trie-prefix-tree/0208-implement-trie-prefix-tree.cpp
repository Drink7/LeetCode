class TrieNode{
public:
    char val;
    TrieNode* letterDict[26];
    bool isWord = false;
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            letterDict[i] = nullptr;
        }
    }

    TrieNode(char in) : TrieNode() {
        val = in;
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insert(string word) {
        // TC: O(len)
        TrieNode* cur = root;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            int charIndex = c - 'a';
            cout << "1: " << charIndex << endl;
            if (cur->letterDict[charIndex] == nullptr) {
                // add new char
                cout << "2: " << charIndex << endl;
                cur->letterDict[charIndex] = new TrieNode(c);
            }
            cout << "3: " << charIndex << endl;
            cur = cur->letterDict[charIndex];
        }
        cur->isWord = true;
    }
    
    bool search(string word) {
        // TC: O(len)
        TrieNode* cur = root;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            int charIndex = c - 'a';
            if (cur->letterDict[charIndex] == nullptr) {
                return false;
            }
            cur = cur->letterDict[charIndex];
        }
        return cur->isWord;
    }
    
    bool startsWith(string prefix) {
        // TC: O(len)
        TrieNode* cur = root;
        for (int i = 0; i < prefix.size(); i++) {
            char c = prefix[i];
            int charIndex = c - 'a';
            if (cur->letterDict[charIndex] == nullptr) {
                return false;
            }
            cur = cur->letterDict[charIndex];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */