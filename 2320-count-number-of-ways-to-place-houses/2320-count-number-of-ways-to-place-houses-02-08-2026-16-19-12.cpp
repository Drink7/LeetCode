class Solution {
public:
    int countHousePlacements(int n) {
        // each side has n house can places
        // we can calculate one side, and use square to check the final houses
        // TC: O(n)
        // SC: O(n)
        dict.resize(n + 1, -1);
        int oneSide = dfs(n);
        int ans = ((long long) oneSide * oneSide) % MOD;
        return ans;
    }

    int dfs(int cur) {
        if (cur <= 0) {
            return 1;
        }

        if (dict[cur] != -1) {
            return dict[cur];
        }

        int result = (dfs(cur - 2) + dfs(cur - 1)) % MOD;
        dict[cur] = result;

        return dict[cur];
    }
private:
    //unordered_map<int, int> dict;
    vector<int> dict;
    int MOD = 1e9 + 7;
};