class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // choose or not choose
        vector<vector<int>> result;
        vector<int> path;

        subsetHelper(nums, result, path, 0);
        return result;
    }

    void subsetHelper(vector<int>& nums, vector<vector<int>>& result, vector<int> path, int start) {
        if (start >= nums.size()) {
            result.push_back(path);
            return;
        }

        subsetHelper(nums, result, path, start + 1);
        path.push_back(nums[start]);
        subsetHelper(nums, result, path, start + 1);
        //path.pop_back();
    }
};