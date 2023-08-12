class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Hash table (unorder_map)
        // TC: O(n)
        // SC: O(n)
        // store val, id
        unordered_map<int, int> dict;
        for (int i = 0; i < nums.size(); i++) {
            int remain = target - nums[i];
            if (dict.count(remain)) {
                return {dict[remain], i};
            } else {
                dict[nums[i]] = i;
            }
        } 
        return {-1, -1};
    }
};