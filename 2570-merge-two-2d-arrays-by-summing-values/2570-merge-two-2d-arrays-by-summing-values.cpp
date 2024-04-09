class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        // two pointer, since the input is sorted in ascending order by id
        // iterate nums1 and nums2, only merge with the same id, or append the smaller id
        // TC: O(m * n), m is nums1 size, n is nums2 size
        // SC: O(1)
        int pointer1 = 0;
        int pointer2 = 0;
        int nums1Cnt = nums1.size();
        int nums2Cnt = nums2.size();
        vector<vector<int>> result;
        while (pointer1 < nums1Cnt && pointer2 < nums2Cnt) {
            int id1 = nums1[pointer1][0];
            int id2 = nums2[pointer2][0];
            if (id1 == id2) {
                result.push_back({id1, nums1[pointer1][1] + nums2[pointer2][1]});
                pointer1++;
                pointer2++;
            } else if (id1 > id2) {
                result.push_back(nums2[pointer2]);
                pointer2++;
            } else {
                result.push_back(nums1[pointer1]);
                pointer1++;
            }
        }

        while (pointer1 < nums1Cnt) {
            result.push_back(nums1[pointer1]);
            pointer1++;
        }

        while (pointer2 < nums2Cnt) {
            result.push_back(nums2[pointer2]);
            pointer2++;
        }
        return result;
    }
};