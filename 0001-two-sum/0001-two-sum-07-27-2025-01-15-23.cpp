class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // unordered_map<int, int>
        // TC: O(n)
        // SC: O(n)
        unordered_map<int, int> dict;
        for (int i = 0; i < nums.size(); i++) {
            int remain = target - nums[i];
            if (dict.count(remain) > 0) {
                return {dict[remain], i};
            }
            dict[nums[i]] = i;
        }
        return {}; // impossible
    }
};