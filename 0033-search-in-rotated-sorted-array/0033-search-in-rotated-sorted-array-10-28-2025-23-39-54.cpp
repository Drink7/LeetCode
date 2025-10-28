class Solution {
public:
    int search(vector<int>& nums, int target) {
        // find the srted part, do twice binary search
        // mid < right -> right part sorted
        // else -> left part sorted
        // 1 2 3 4 5 O
        // 2 3 4 5 1 
        // 3 4 5 1 2
        // 4 5 1 2 3 O
        // 5 1 2 3 4 O
        // find which side is sorted
        // left part
        // if left < target <= mid, right = mid
        // else left + 1
        // right part
        // if mid < target && target <= right
        // left + 1
        // else right = mid
        // TC: O(logn)
        // SC: O(1)
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) return mid;

            if (nums[mid] < nums[right]) {
                // right part sorted
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {
                // left part sorted
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        return -1;

        /*
        // find minimum
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        // min: left
        int midId = left;

        // check which side
        if (nums[midId] <= target && target <= nums[nums.size() - 1]) {
            // right side
            left = midId;
            right = nums.size() - 1;
        } else {
            // left side
            left = 0;
            right = midId;
        }

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
        */
    }
};