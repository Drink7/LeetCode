class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // two pointer
        // TC: O(n)
        // SC: O(1)
        int uniqueId = 0;
        for (int i = 0; i < nums.size(); i++) {
            int uniqueNum = nums[i];
            int cnt = 1;
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
                i++;
                cnt++;
            }

            if (cnt >= 2) {
                nums[uniqueId++] = uniqueNum;
                nums[uniqueId++] = uniqueNum;
            } else {
                nums[uniqueId++] = uniqueNum;
            }
        }
        return uniqueId;
    }
};