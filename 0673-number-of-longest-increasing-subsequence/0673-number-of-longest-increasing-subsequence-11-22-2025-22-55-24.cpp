class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        // calculate LIS and record the freq
        // TC: O(n)
        // SC: O(n)
        int n = nums.size();
        vector<int> dpLen(n, 1);
        vector<int> dpCnt(n, 1);
        int maxLen = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // calculate LIS
                if (nums[j] < nums[i]) {
                    if (dpLen[j] + 1 > dpLen[i]) {
                        dpLen[i] = dpLen[j] + 1;
                        dpCnt[i] = dpCnt[j];
                    } else if (dpLen[j] + 1 == dpLen[i]) {
                        dpCnt[i] += dpCnt[j];
                    }
                }
            }
            maxLen = max(maxLen, dpLen[i]);
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            if (dpLen[i] == maxLen) {
                result += dpCnt[i];
            }
        }
        return result;
    }
};