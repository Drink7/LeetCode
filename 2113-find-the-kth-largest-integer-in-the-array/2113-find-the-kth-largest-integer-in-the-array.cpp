class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        // Quick select
        // TC: O(n^2)
        // SC: O(n) call stack
        // find k-th largest, quick select would find k-th min
        //return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
        // Use STL
        // TC: O(N * M)
        // SC: O(N)
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), strNumComparator);
        return nums[k - 1];
    }

    string quickSelect(vector<string>& nums, int left, int right, int k) {
        if (left == right) {
            return nums[left];
        }

        int pivot = partition(nums, left, right);
        if (pivot == k) {
            return nums[k];
        } else if (pivot < k) {
            return quickSelect(nums, pivot + 1, right, k);
        } else {
            return quickSelect(nums, left, pivot - 1, k);
        }
    }

    int partition(vector<string>& nums, int left, int right) {
        int i = left;
        for (int j = left; j < right; j++) {
            if (!strNumComparator(nums[j], nums[right])) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[right]);
        return i;
    }

    static bool strNumComparator(string &a, string &b) {
        if (a.size() == b.size()) {
            return a > b;
        } else {
            return a.size() > b.size();
        }
    }
};