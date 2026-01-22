class Solution {
public:
    int climbStairs(int n) {
        return dfs(n);
    }

    int dfs(int i) {
        if (i == 0 || i == 1) {
            return 1;
        }

        if (dict.count(i)) {
            return dict[i];
        }

        int result = dfs(i - 1) + dfs(i - 2);
        dict[i] = result;
        return dict[i];
    }
private:
    unordered_map<int, int> dict;
};