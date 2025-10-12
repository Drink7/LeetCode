class Solution {
/*
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Backtracking + prune
        // TLE
        dfs(s1, s2, s3, 0, 0, "");
        return dict.count(s3) == 1;
    }

    void dfs(string& s1, string& s2, string& s3, int s1Index, int s2Index, string strCur) {
        // prune
        if (s3.find(strCur) != 0) {
            return;
        }

        if (s1Index == s1.size() && s2Index == s2.size()) {
            dict.insert(strCur);
            return;
        }

        if (s1Index < s1.size()) {
            dfs(s1, s2, s3, s1Index + 1, s2Index, strCur + s1[s1Index]);
        }

        if (s2Index < s2.size()) {
            dfs(s1, s2, s3, s1Index, s2Index + 1, strCur + s2[s2Index]);
        }
    }

private:
    unordered_set<string> dict;
*/

public:
    bool isInterleave(string s1, string s2, string s3) {
        // 2D-DP
        // TC: O(m * n)
        // SC: O(m * n)
        int m = s1.size();
        int n = s2.size();
        if (s3.size() != m + n) {
            return false;
        }

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
        // init starting point
        dp[0][0] = true;

        // init first row
        for (int i = 1; i <= m; i++) {
            dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
        }

        // init first col
        for (int i = 1; i <= n; i++) {
            dp[0][i] = dp[0][i - 1] && (s2[i - 1] == s3[i - 1]);
        }

        // calculate inner interleave
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1]) ||
                            dp[i][j - 1] && (s2[j - 1] == s3[i + j - 1]);
            }
        }
        return dp[m][n];
    }
    
};