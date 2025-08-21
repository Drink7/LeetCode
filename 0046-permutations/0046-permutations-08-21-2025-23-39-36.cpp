class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // used array to memo used index
        // TC: O(n!)
        // SC: O(n)
        vector<vector<int>> result;
        vector<int> path;
        vector<int> used(nums.size(), 0);
        permuteHelper(result, nums, used, path);
        return result;
    }

    void permuteHelper(vector<vector<int>>& result, vector<int>& nums, vector<int>& used, vector<int>& path) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == 1) {
                continue;
            }
            used[i] = 1;
            path.push_back(nums[i]);

            permuteHelper(result, nums, used, path);

            path.pop_back();
            used[i] = 0;
        }
    }
};