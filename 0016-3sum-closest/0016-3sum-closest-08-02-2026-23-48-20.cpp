class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // -4, -1, 1, 2
        // same logic as 3 sum but find the closet one
        // sort, then use two pointer to find the closet 3 sum
        // use abs to find the closet
        // TC: O(n^2)
        // SC: O(1)
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int result = nums[0] + nums[1] + nums[2]; // default
        int minDiff = abs(result - target);
        for (int i = 0; i < n - 2; i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                int left = i + 1;
                int right = n - 1;
                while (left < right) {
                    int sum = nums[i] + nums[left] + nums[right];
                    if (abs(sum - target) < minDiff) {
                        minDiff = abs(sum - target);
                        result = sum;
                    }

                    if (sum - target == 0) {
                        return sum;
                    } else if (sum - target > 0) {
                        right--;
                    } else {
                        left++;
                    }
                }
            }
        }
        return result;
    }
};