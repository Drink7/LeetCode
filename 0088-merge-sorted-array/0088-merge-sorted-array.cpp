class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        /*
        // use a copy array of nums1 with m size
        // TC: O(2m + n)
        // SC: O(m)
        vector<int> copyNums1(m);
        copyNums1.assign(nums1.begin(), nums1.begin() + m);

        // merge copyNums1 and nums2 to nums1
        // merge sort
        int n1 = 0;
        int n2 = 0;
        int index = 0;
        while (n1 < m && n2 < n) {
            if (copyNums1[n1] > nums2[n2]) {
                nums1[index] = nums2[n2];
                n2++;
            } else {
                nums1[index] = copyNums1[n1];
                n1++;
            }
            index++;
        }

        while (n1 < m) {
            nums1[index] = copyNums1[n1];
            n1++;
            index++;
        }

        while (n2 < n) {
            nums1[index] = nums2[n2];
            n2++;
            index++;
        }
        */

        // Sort it from the end
        // TC: O(m + n)
        // SC: O(1)
        int n1 = m - 1;
        int n2 = n - 1;
        int index = m + n - 1;
        while (index >= 0) {
            if (n1 >= 0 && n2 >= 0) {
                if (nums1[n1] > nums2[n2]) {
                    nums1[index] = nums1[n1];
                    n1--;
                } else {
                    nums1[index] = nums2[n2];
                    n2--;
                }
            } else {
                if (n1 >= 0) {
                    nums1[index] = nums1[n1];
                    n1--;
                }

                if (n2 >= 0) {
                    nums1[index] = nums2[n2];
                    n2--;
                }
            }
            index--;
        }
    }
};