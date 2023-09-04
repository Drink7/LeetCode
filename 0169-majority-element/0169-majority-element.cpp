class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*
        // hash table
        // TC: O(n)
        // SC: O(n)
        unordered_map<int, int> dict;
        for (auto const& num : nums) {
            dict[num]++;
        }

        int majorityCount = 0;
        int majorityElement = 0;
        for (auto const& p : dict) {
            if (p.second > majorityCount) {
                majorityCount = p.second;
                majorityElement = p.first;
            }
        }
        return majorityElement;
        */
        // Boyer–Moore majority vote algorithm
        // TC: O(1)
        // SC: O(1)
        int base = 0;
        int baseCnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (base == nums[i]) {
                baseCnt++;
            } else {
                if (baseCnt == 0) {
                    base = nums[i];
                    baseCnt++;
                } else {
                    baseCnt--;   
                }
            }
        }
        return base;
    }
};