class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        /*
        // Brute Force
        // TC: O(m*n) -> m is nums1 size, n is nums2 size
        // SC: O(m)
        vector<int> result(nums1.size(), -1);
        for (int i = 0; i < nums1.size(); i++) {
            int num = nums1[i];
            int startId = find(nums2.begin(), nums2.end(), num) - nums2.begin();
            for (int j = startId; j < nums2.size(); j++) {
                if (nums2[j] > num) {
                    result[i] = nums2[j];
                    break;
                }
            }
        }
        return result;
        */

        // monotonic stack
        // TC :O(n), n is for nums2 size
        // SC: O(n)
        int n = nums2.size();
        vector<int> result;
        vector<int> monoResult(n, -1);
        unordered_map<int, int> dict;
        stack<int> stk;

        for (int i = 0; i < n; i++) {
            while (!stk.empty() && nums2[stk.top()] < nums2[i]) {
                monoResult[stk.top()] = nums2[i];
                dict[nums2[stk.top()]] = monoResult[stk.top()];
                stk.pop();
            }
            stk.push(i);
        }

        for (int i = 0; i < nums1.size(); i++) {
            if (dict.count(nums1[i]) < 1) {
                result.push_back(-1);
            } else {
                result.push_back(dict[nums1[i]]);
            }
        }
        return result;
    }
};