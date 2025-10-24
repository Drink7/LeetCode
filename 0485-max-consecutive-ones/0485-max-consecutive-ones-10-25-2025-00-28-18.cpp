class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        /*
        // find maximum consecutive
        // TC: O(n)
        // SC: O(1)
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                int count = 0;
                int j = i;
                for (; j < nums.size(); j++) {
                    if (nums[j] == 1) {
                        count++;
                    } else {
                        break;
                    }
                }
                result = max(result, count);
                i = j;
            }
        }
        return result;
        */

        // Elegant code
        // TC: O(n)
        // SC: O(1)
        int result = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count++;
                result = max(result, count);
            } else {
                count = 0;
            }
        }
        return result;
    }
};