class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // Hash table
        // TC: O(n)
        // SC: O(n)
        unordered_map<int, int> numDict;
        vector<int> result;
        int n1 = nums1.size();
        int n2 = nums2.size();
        if (n1 >= n2) {
            for (auto const& num : nums1) {
                numDict[num]++;
            }

            // add answer to result vector
            for (auto const& num : nums2) {
                if (numDict.count(num)) {
                    result.push_back(num);
                    numDict[num]--;
                    if (numDict[num] == 0) {
                        numDict.erase(num);
                    }
                }
            }
        } else {
            result = intersect(nums2, nums1);
        }
        return result;
    }
};