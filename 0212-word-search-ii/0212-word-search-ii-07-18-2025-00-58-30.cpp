class TrieNode{
public:
    char c = '\0';
    unordered_map<char, TrieNode*> childMap;
    bool isWord = false;

    TrieNode() {
    }

    TrieNode(char in) {
        c = in;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // DFS + Trie
        // make words trie
        root = new TrieNode();

        vector<string> result;

        // insert, build Trie
        for (auto const& word : words) {
            TrieNode* cur = root;
            for (auto const& c : word) {
                if (cur->childMap.count(c) < 1) {
                    TrieNode* node = new TrieNode(c);
                    cur->childMap[c] = node;
                }
                cur = cur->childMap[c];
            }
            cur->isWord = true;
        }

        // dfs, traverse
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                char cur = board[i][j];
                if (root->childMap.count(cur) > 0) {
                    // exist, search
                    string ans = string("") + cur;
                    dfs(board, result, i, j, root->childMap[cur], ans);
                }
            }
        }
        return result;
    }

    void dfs(vector<vector<char>>& board, vector<string>& result, int row, int col, TrieNode* node, string path) {
        if (node == nullptr) {
            return;
        }

        if (node->isWord) {
            result.push_back(path);

            // prune, avoid duplicate
            node->isWord = false;
        }

        char tmp = board[row][col];
        board[row][col] = '#';

        for (int i = 0; i < 4; i++) {
            int newRow = row + dRow[i];
            int newCol = col + dCol[i];
            if (newRow < 0 || newRow >= board.size() || newCol < 0 || newCol >= board[0].size() ||
                board[newRow][newCol] == '#' || node->childMap.count(board[newRow][newCol]) < 1) {
                continue;
            }

            dfs(board, result, newRow, newCol, node->childMap[board[newRow][newCol]], path + board[newRow][newCol]);
        }

        board[row][col] = tmp;
    }
private:
    TrieNode* root;
    int dRow[4] = {-1, 0, 1, 0};
    int dCol[4] = {0, -1, 0, 1};
};