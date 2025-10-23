class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // i1 for nums1 pointer
        // i2 for nums2 pointer
        // for i = m + n - 1; i >= 0; i--
        // when i1 >= 0 || i2 >= 0, compare nums[i1] and nums[i2], place bigger one
        // else keep placing until both < 0
        // TC: O(m + n)
        // SC: O(1)
        int i1 = m - 1;
        int i2 = n - 1;
        int index = m + n - 1;
        while (i1 >= 0 && i2 >= 0) {
            if (nums1[i1] > nums2[i2]) {
                nums1[index--] = nums1[i1--];
            } else {
                nums1[index--] = nums2[i2--];
            }
        }

        while (i2 >= 0) {
            nums1[index--] = nums2[i2--];
        }
    }
};