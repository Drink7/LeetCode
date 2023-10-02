class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        /*
        // hash set
        // TC: O(n)
        // SC: O(n)
        vector<int> result;
        unordered_set<int> numSet;
        for (auto const& num : nums) {
            if (numSet.count(num)) {
                result.push_back(num);
            }
            numSet.insert(num);
        }

        for (int i = 0; i < nums.size(); i++) {
            if (numSet.count(i + 1) < 1) {
                result.push_back(i + 1);
                break;
            }
        }
        return result;
        */

        // TC: O(n)
        // SC: O(1)
        // find dup
        int dup = -1;
        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0) {
                dup = abs(nums[i]);
            } else {
                nums[index] = -nums[index];
            }
        }

        // find missing
        int missing = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                missing = i + 1;
                break;
            }
        }
        return {dup, missing};
    }
};