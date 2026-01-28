class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        // climbing stairs concept
        // each time use zero string or one string
        // until target length, the target length is from low to high
        // steps is zero and one, find how many way to get to the stairs[low] - stairs[high]
        int result = 0;
        for (int i = low; i <= high; i++) {
            result = (result + dfs(i, zero, one)) % MOD;
        }
        return result;
    }

    int dfs(int cur, int& zero, int& one) {
        if (cur == 0) {
            return 1;
        }

        if (dict.count(cur)) {
            return dict[cur];
        }

        int result = 0;
        if (cur - zero >= 0) {
            result = (result + dfs(cur - zero, zero, one)) % MOD;
        }

        if (cur - one >= 0) {
            result = (result + dfs(cur - one, zero, one)) % MOD;
        }

        dict[cur] = result;

        return dict[cur];
    }
private:
    int MOD = 1e9 + 7;
    unordered_map<int, int> dict;
};