class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // merge sort
        // TC: O(nlogn)
        // SC: O(n)
        vector<int> result = mergeSort(nums, 0, nums.size() - 1);
        return result;
    }

    vector<int>  mergeSort(vector<int>& nums, int left, int right) {
        if (left > right) {
            return {};
        }

        if (left == right) {
            return {nums[left]};
        }

        int mid = left + (right - left) / 2;
        vector<int> leftNums = mergeSort(nums, left, mid);
        vector<int> rightNums = mergeSort(nums, mid + 1, right);
        return merge(leftNums, rightNums);
    }

    vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        int index1 = 0;
        int index2 = 0;
        while (index1 < nums1.size() && index2 < nums2.size()) {
            if (nums1[index1] > nums2[index2]) {
                result.push_back(nums2[index2]);
                index2++;
            } else {
                result.push_back(nums1[index1]);
                index1++;
            }
        }

        if (index1 < nums1.size()) {
            for (int i = index1; i < nums1.size(); i++) {
                result.push_back(nums1[i]);
            }
        }

        if (index2 < nums2.size()) {
            for (int i = index2; i < nums2.size(); i++) {
                result.push_back(nums2[i]);
            }
        }
        return result;
    }
};