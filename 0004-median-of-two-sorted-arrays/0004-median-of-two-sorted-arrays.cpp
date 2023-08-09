class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Binary Search
        // TC: O(log(m + n))
        // SC: O(1)
        int m = nums1.size();
        int n = nums2.size();
        // Always make nums1 size < nums2 size
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int total = m + n;
        int half = total / 2;

        // make binary search on nums1
        int left = 0;
        int right = m - 1;
        while (true) {
            // Note:
            // When calculating i, integer division in C/C++/Java rounds towards 0 rather than towards -infinity (like Python does).
            // the line i = (l + r) / 2 needs to account for this (my solution uses i = l > r ? -1 : (l + r) / 2;)
            int nums1Mid = (left <= right) ? left + (right - left) / 2 : -1;
            
            // Both nums1 and nums2 is 0-indexed
            int nums2Mid = half - (nums1Mid + 1) - 1;

            // Note the boundary case
            int nums1Left = nums1Mid >= 0 ? nums1[nums1Mid] : INT_MIN;
            int nums1Right = nums1Mid + 1 < m ? nums1[nums1Mid + 1] : INT_MAX;
            int nums2Left = nums2Mid >= 0 ? nums2[nums2Mid] : INT_MIN;
            int nums2Right = nums2Mid + 1 < n ? nums2[nums2Mid + 1] : INT_MAX;

            //cout << "nums1Mid: " << nums1Mid << ", nums2Mid: " << nums2Mid << endl;
            //cout << "nums1Left: " << nums1Left << ", nums1Right: " << nums1Right << endl;
            //cout << "nums2Left: " << nums2Left << ", nums2Right: " << nums2Right << endl;
            if (nums1Left <= nums2Right && nums2Left <= nums1Right) {
                // check odd or even
                if (total % 2 == 1) {
                    return min(nums1Right, nums2Right);
                } else {
                    return (max(nums1Left, nums2Left) + min(nums1Right, nums2Right)) / 2.0;
                }
            } else if (nums1Left > nums2Right) {
                right = nums1Mid - 1;
            } else {
                left = nums1Mid + 1;
            }
        }
    }
};