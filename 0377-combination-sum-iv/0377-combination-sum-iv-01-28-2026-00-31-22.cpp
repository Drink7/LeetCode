class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if (target == 0) {
            return 1;
        }

        if (target < 0) {
            return 0;
        }

        if (dict.count(target)) {
            return dict[target];
        }

        // climbing to the stairs - target needs ? steps
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            result += combinationSum4(nums, target - nums[i]);
        }

        dict[target] = result;

        return dict[target];
    }
private:
    unordered_map<int, int> dict;
};