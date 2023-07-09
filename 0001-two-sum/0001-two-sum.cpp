class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // TC: O(n)
        // SC: O(n)
        unordered_map<int, int> dict;
        for (int i = 0; i < nums.size(); i++) {
            int remain = target - nums[i];
            if (dict.count(remain)) {
                return {i, dict[remain]};
            }
            dict[nums[i]] = i;
        }

        // impossible
        return {-1, -1};
    }
};