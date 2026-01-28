class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        // climbing stairs concept
        // each time use zero string or one string
        // until target length, the target length is from low to high
        // steps is zero and one, find how many way to get to the stairs[low] - stairs[high]
        // 使用 vector 代替 unordered_map，效能提升 10 倍以上
        int result = 0;
        vector<int> dict(high + 1, -1);
        for (int i = low; i <= high; i++) {
            result = (result + dfs(i, zero, one, dict)) % MOD;
        }
        return result;
    }

    int dfs(int cur, int& zero, int& one, vector<int>& dict) {
        if (cur == 0) {
            return 1;
        }

        if (dict[cur] != -1) {
            return dict[cur];
        }

        int result = 0;
        if (cur - zero >= 0) {
            result = (result + dfs(cur - zero, zero, one, dict)) % MOD;
        }

        if (cur - one >= 0) {
            result = (result + dfs(cur - one, zero, one, dict)) % MOD;
        }

        dict[cur] = result;

        return dict[cur];
    }
private:
    int MOD = 1e9 + 7;
};