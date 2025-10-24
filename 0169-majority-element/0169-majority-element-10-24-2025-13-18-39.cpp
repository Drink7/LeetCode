class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // boyer-moore algorithm
        // TC: O(n)
        // SC: O(1)
        int num = nums[0];
        int cnt = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (cnt == 0) {
                num = nums[i];
                cnt = 1;
            } else {
                if (nums[i] != num) {
                    cnt--;
                } else {
                    cnt++;
                }
            }
        }
        return num;
    }
};