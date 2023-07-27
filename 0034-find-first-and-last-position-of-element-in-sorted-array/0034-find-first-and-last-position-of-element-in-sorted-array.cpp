class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // Binary Search with find the first element and last element index
        // TC: O(logn)
        // SC: O(1)
        int firstIndex = findFirstPos(nums, target);
        int lastIndex = findLastPos(nums, target);
        cout << firstIndex << endl;
        cout << lastIndex << endl;
        return {firstIndex, lastIndex};
    }

    int findFirstPos(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                if (mid == 0 || nums[mid - 1] != target) {
                    return mid;
                } else {
                    high = mid - 1;
                }
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }

    int findLastPos(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                if (mid == nums.size() - 1 || nums[mid + 1] != target) {
                    return mid;
                } else {
                    low = mid + 1;
                }
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
};