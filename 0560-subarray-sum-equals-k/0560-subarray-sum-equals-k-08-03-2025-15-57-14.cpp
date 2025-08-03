class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // can not use sliding window since the negative value
        // subarray sum -> prefix sum
        // we only care about number -> hash map <prefix sum, count>
        // TC: O(n)
        // SC: O(n)
        unordered_map<int, int> dict; // dict store before index i, prefix sum = k's count
        dict[0] = 1;
        int prefixSum = 0;
        int result = 0;
        for (auto const& num : nums) {
            prefixSum += num;
            if (dict.count(prefixSum - k) > 0) {
                result += dict[prefixSum - k];
            }
            dict[prefixSum]++;
        }
        return result;
    }
};