class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // prefix sum, also find prefixSum - k exist or not
        // TC: O(n)
        // SC: O(n)
        unordered_map<int, int> dict; // sum, count
        int prefixSum = 0;
        int result = 0;

        dict[0] = 1;
        for (auto const& num : nums) {
            prefixSum += num;
            int remain = prefixSum - k;
            if (dict.count(remain) > 0) {
                result += dict[remain];
            }
            dict[prefixSum]++;
        }
        return result;
    }
};