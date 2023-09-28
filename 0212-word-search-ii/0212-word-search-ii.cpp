class Solution {
    class TrieNode {
        public:
            bool isWord = false;
            char c;
            unordered_map<char, TrieNode*> dict;
            TrieNode() {
            }

            TrieNode(char in) {
                c = in;
            }
    };
    class Trie {
        public:
            Trie() {
                root = new TrieNode();
            }

            void add(string word) {
                TrieNode* cur = root;
                for (auto const& c : word) {
                    if (cur->dict.count(c) < 1) {
                        cur->dict[c] = new TrieNode(c);
                    }
                    cur = cur->dict[c];
                }
                cur->isWord = true;
            }
            TrieNode* root;
    };
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // Backtracking + Trie
        Trie* trie = new Trie();

        // add words
        for (auto const& str : words) {
            trie->add(str);
        }

        // search word
        vector<string> result;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                search(trie->root, board, result, i, j, "");
            }
        }
        return result;
    }

    void search(TrieNode* root, vector<vector<char>>& board, vector<string>& result, int row, int col, string path) {
        if (row < 0 || row >= board.size() ||
            col < 0 || col >= board[0].size() ||
            board[row][col] == '#' || root->dict.count(board[row][col]) < 1) {
            return;
        }

        char c = board[row][col];
        path += c;
        root = root->dict[c];
        board[row][col] = '#';
        if (root->isWord) {
            root->isWord = false;
            result.push_back(path);
        }

        int dRow[4] = {-1, 0, 1, 0};
        int dCol[4] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            search(root, board, result, row + dRow[i], col + dCol[i], path);
        }
        board[row][col] = c;
    }
};