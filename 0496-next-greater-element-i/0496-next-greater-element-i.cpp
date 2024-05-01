class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        /*
        // brute force
        // TC: O(n^2)
        // SC: O(1)
        vector<int> result;
        for (auto const& num : nums1) {
            int indexFound = -1;
            for (int i = 0; i < nums2.size(); i++) {
                if (num == nums2[i]) {
                    // start find next greater
                    indexFound = i;
                    break;
                }
            }
            if (indexFound != -1) {
                int nextGreater = -1;
                for (int i = indexFound; i < nums2.size(); i++) {
                    if (nums2[i] > num) {
                        nextGreater = nums2[i];
                        break;
                    }
                }
                result.push_back(nextGreater);
            } else {
                // it should not happen
            }
        }
        return result;
        */
        // monotonic stack, check next greater element in nums2
        // traverse from back
        // TC: O(m + n)
        // SC: O(n)
        vector<int> result;
        stack<int> monoStack;
        unordered_map<int, int> dict;
        int n = nums2.size();
        for (int i = n - 1; i >= 0; i--) {
            if (monoStack.empty()) {
                dict[nums2[i]] = -1;
            } else {
                while (!monoStack.empty() && nums2[monoStack.top()] < nums2[i]) {
                    monoStack.pop();
                }

                if (monoStack.empty()) {
                    dict[nums2[i]] = -1;
                } else {
                    dict[nums2[i]] = nums2[monoStack.top()];
                }
            }
            monoStack.push(i);
        }

        for (auto const& num : nums1) {
            result.push_back(dict[num]);
        }
        return result;
    }
};