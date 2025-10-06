class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // couting bucket sort -> Memory Limit Exceeded
        // TC: O(n)
        // SC: O(10^5)
        /*
        int bucket[100001];
        int n = nums.size();
        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            bucket[nums[i] + 50000]++;
        }

        for (int i = 0; i < 100001; i++) {
            if (bucket[i] != 0) {
                for (int j = 0; j < bucket[i]; j++) {
                    result.push_back(i - 50000);
                }
            }
        }
        return result;
        */
        // merge sort
        // TC: O(nlogn)
        // SC: O(logn)
        int n = nums.size();
        mergesort(nums, 0, n - 1);
        return nums;
    }

    void mergesort(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return;
        }
        int mid = left + (right - left) / 2;
        mergesort(nums, left, mid);
        mergesort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }

    void merge(vector<int>& nums, int left, int mid, int right) {
        if (left >= right) {
            return;
        }
        int i = left;
        int j = mid + 1;
        int k = 0;
        int n = right - left + 1;
        vector<int> sorted(n);
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                sorted[k++] = nums[i++];
            } else {
                sorted[k++] = nums[j++];
            }
        }

        while (i <= mid) {
            sorted[k++] = nums[i++];
        }
        
        while (j <= right) {
            sorted[k++] = nums[j++];
        }

        for (k = 0; k < n; k++) {
            nums[k + left] = sorted[k];
        }
    }
};