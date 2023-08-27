class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        // hash table -> hash map, similar to two sum
        // TC: O(mnop), mnop is nums1 ~ nums4 size
        // SC: O(mn)
        unordered_map<int, int> dict;
        int result = 0;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                dict[nums1[i] + nums2[j]]++;
            }
        }

        // check if -(nums3 + nums4) exist in the dict and count the sum
        for (int i = 0; i < nums3.size(); i++) {
            for (int j = 0; j < nums4.size(); j++) {
                if (dict.count(-(nums3[i] + nums4[j]))) {
                    result += dict[-(nums3[i] + nums4[j])];
                }
            }
        }
        return result;
    }
};