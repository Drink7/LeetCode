class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        // sliding window + hash map
        // TC: O(n)
        // SC: O(n)
        int n = nums.size();
        unordered_map<int, long long> numMap;
        int left = 0, right = 0;
        long long result = 0;
        long long pairCnt = 0;
        while (right < n) {
            // add num[right] to hash map
            pairCnt += numMap[nums[right]];
            numMap[nums[right]]++;

            // move left
            while(pairCnt >= k) {
                numMap[nums[left]]--;
                pairCnt -= numMap[nums[left]];
                left++;
            }

            // add all good subarray that end with right index
            result += left;
            right++;
        }
        return result;
    }
};