class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*
        // TC: O(n^2)
        // SC: O(1)
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
        */
        // TC: O(n)
        // SC: O(n)
        unordered_map<int, int> idxMap;
        for (int i = 0; i < nums.size(); i++) {
            int remain = target - nums[i];
            if (idxMap.count(remain) > 0) {
                return {i, idxMap[remain]};
            }
            idxMap[nums[i]] = i;
        }
        return {};
    }
};