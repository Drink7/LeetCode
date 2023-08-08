class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        /*
        // MaxHeap Priority Queue
        // TC: O(nlogn + k)
        // SC: O(n)
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (auto const& num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        return minHeap.top();
        */
        // Quick Select
        // find k largest, quick select n - k large
        // TC: O(n)
        // SC: O(1)
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }

    int quickSelect(vector<int>& nums, int left, int right, int k) {
        if (left == right) {
            return nums[left];
        }

        int pivot = partition(nums, left, right);
        if (pivot == k) {
            return nums[k];
        } else if (pivot > k) {
            return quickSelect(nums, left, pivot - 1, k);
        } else {
            return quickSelect(nums, pivot + 1, right, k);
        }
    }

    int partition(vector<int>& nums, int left, int right) {
        int i = left;
        int pivot = nums[right];
        for (int j = left; j < right; j++) {
            if (nums[j] <= pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[right]);
        return i;
    }
};