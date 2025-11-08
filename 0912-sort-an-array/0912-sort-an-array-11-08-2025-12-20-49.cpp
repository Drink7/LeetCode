class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // merge sort
        // [5 2] [3 1]
        // [5] [2] [3] [1]
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return;
        }

        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }

    void merge(vector<int>& nums, int left, int mid, int right) {
        if (left >= right) {
            return;
        }

        int start1 = left;
        int start2 = mid + 1;
        int k = 0;
        vector<int> sorted(right - left + 1, 0);

        while (start1 <= mid && start2 <= right) {
            if (nums[start1] < nums[start2]) {
                sorted[k++] = nums[start1++];
            } else {
                sorted[k++] = nums[start2++];
            }
        }

        while (start1 <= mid) {
            sorted[k++] = nums[start1++];
        }

        while (start2 <= right) {
            sorted[k++] = nums[start2++];
        }

        for (int i = 0; i < sorted.size(); i++) {
            nums[i + left] = sorted[i];
        }
    }
};