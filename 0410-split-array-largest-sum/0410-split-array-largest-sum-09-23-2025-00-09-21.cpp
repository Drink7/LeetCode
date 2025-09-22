class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        // binary search [max(nums), sum[nums])
        // cut nums.size() or cut 1 time
        // find last cut <= k 
        // TC: O(n + logn)
        // SC: O(1)
        int low = 0;
        int high = 0;
        int result = 0;
        for (auto const& num : nums) {
            high += num;
            low = max(low, num);
        }
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (!canSplit(nums, mid, k)) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    bool canSplit(vector<int>& nums, int target, int k) {
        int sum = 0;
        int cnt = 1;
        for(auto const& num : nums) {
            if (sum + num > target) {
                cnt++;
                sum = num;
            } else {
                sum += num;
            }
        }
        return cnt <= k;
    }
};