class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*
        // unordered_map, and find count > n /2
        // TC: O(n)
        // SC: O(n)
        int n = nums.size();
        unordered_map<int, int> dict;
        for (auto const& num : nums) {
            dict[num]++;
        }

        for (auto const& p : dict) {
            if (p.second >= n / 2 + 1) {
                return p.first;
            }
        }
        return -1; // impossible;
        */

        // Boyer–Moore majority vote algorithm
        // TC: O(n)
        // SC: O(1)
        int maxNumber = nums[0];
        int maxCnt = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (maxNumber == nums[i]) {
                maxCnt++;
            } else {
                if (maxCnt == 0) {
                    maxNumber = nums[i];
                    maxCnt = 1;
                } else {
                    maxCnt--;
                }
            }
        }
        return maxNumber;
    }
};