class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<vector<int>> result;
        vector<int> path;
        dfs(result, path, nums, k, n, 0, 0);
        return result;
    }

    void dfs(vector<vector<int>>& result, vector<int>& path, int nums[], int k, int n, int start, int sum) {
        if (path.size() > k) {
            return;
        }

        if (path.size() == k) {
            if (sum == n) {
                result.push_back(path);
            } else {
                return;
            }
        }

        for (int i = start; i < 9; i++) {
            sum += nums[i];
            path.push_back(nums[i]);
            dfs(result, path, nums, k, n, i + 1, sum);
            path.pop_back();
            sum -= nums[i];
        }
    }
};