class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        // 2D prefix sum
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));

        // Step 1. Prefix sum
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }

        // Step 2. Binary search for side length
        int left = 0, right = min(m, n) + 1;  // [left, right)
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (check(prefix, mid, threshold)) {
                left = mid + 1;  // try bigger square
            } else {
                right = mid;     // too big, shrink
            }
        }

        // left - 1 will be the last <= threshold
        return left - 1;
    }

    bool check(vector<vector<int>>& prefix, int len, int threshold) {
        if (len == 0) return true;
        int m = prefix.size() - 1;
        int n = prefix[0].size() - 1;

        for (int i = len; i <= m; i++) {
            for (int j = len; j <= n; j++) {
                int sum = prefix[i][j]
                        - prefix[i - len][j]
                        - prefix[i][j - len]
                        + prefix[i - len][j - len];
                if (sum <= threshold) return true;
            }
        }
        return false;
    }
};