class TrieNode {
public:
    char c = '\0';
    vector<TrieNode*> child = vector<TrieNode*>(26, nullptr);
    bool isWord = false;

    TrieNode(){
    }
    TrieNode(char in) {
        c = in;
    }
};

class Solution {
public:
    TrieNode* root;

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> result;
        root = new TrieNode();

        sort(products.begin(), products.end());
        for (auto const& product : products) {
            addWord(product);
        }

        string prefix = "";
        for (char c : searchWord) {
            prefix += c;
            result.push_back(getSuggestions(prefix, 3));
        }
        return result;
    }

    vector<string> getSuggestions(string& prefix, int count) {
        TrieNode* cur = root;
        for (char c : prefix) {
            if (!cur->child[c - 'a']) {
                return {};
            }
            cur = cur->child[c - 'a'];
        }

        vector<string> suggest;
        dfs(cur, prefix, suggest, count);
        return suggest;
    }

    void dfs(TrieNode* node, string path, vector<string>& suggest, int& count) {
        if (!node || count == 0) {
            return;
        }

        if (node->isWord) {
            suggest.push_back(path);
            count--;
        }

        for (int i = 0; i < 26 && count > 0; i++) {
            if (node->child[i]) {
                path += (char) i + 'a';
                dfs(node->child[i], path, suggest, count);
                path.pop_back();
            }
        }
    }

    void addWord(const string& word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (!cur->child[c - 'a']) {
                cur->child[c - 'a'] = new TrieNode(c);
            }
            cur = cur->child[c - 'a'];
        }
        cur->isWord = true;
    }
};
