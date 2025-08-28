class Solution {
public:
    int subarraySum(vector<int>& nums) {
        // prefix sum
        vector<int> prefixSum;
        prefixSum.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            prefixSum.push_back(prefixSum.back() + nums[i]);
        }

        int result = 0;
        // calculate
        for (int i = 0; i < nums.size(); i++) {
            int start = max(0, i - nums[i]);
            if (start > 0) {
                result += prefixSum[i] - prefixSum[start - 1];
            } else {
                result += prefixSum[i] ;
            }
        }
        return result;
    }
};