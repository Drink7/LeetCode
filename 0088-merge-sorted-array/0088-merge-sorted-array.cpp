class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Cheating STL answer (Array + sorting)
        // TC: O(mlogm + n)
        // SC: O(1)
        for (int i = 0; i < n; i++) {
            nums1[i + m] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }
};