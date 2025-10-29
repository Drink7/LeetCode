class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        // check the left side and right side of 0, if their sum is equal, it must be a valid ans
        // TC: O(n^2)
        // SC: O(1)
        /*
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                // corner case
                int left = sumHelper(0, i - 1, nums);
                int right = sumHelper(i + 1, n - 1, nums);
                if (left == right) {
                    cnt += 2;
                } else if (abs(left - right) <= 1) {
                    cnt++;
                }
            }
        }
        return cnt;
        */
        int n = nums.size();
        int cnt = 0;
        vector<int> prefix(n + 1, 0); // prev i numbers sum
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }

        // traverse the prfix sum
        for (int i = 1; i <= n; i++) {
            if (nums[i - 1] == 0) {
                int leftSum = prefix[i - 1];
                int rightSum = prefix[n] - prefix[i];

                if (leftSum - rightSum >= 0 && leftSum - rightSum <= 1) {
                    // can go left
                    cnt++;
                } 

                if (rightSum - leftSum >= 0 && rightSum - leftSum <= 1) {
                    // can go left
                    cnt++;
                } 
            }
        }
        return cnt;
    }

    int sumHelper(int start, int end, vector<int>& nums) {
        if (end < start) {
            return 0;
        }

        int sum = 0;
        for (int i = start; i <= end; i++) {
            sum += nums[i];
        }
        return sum;
    }
};