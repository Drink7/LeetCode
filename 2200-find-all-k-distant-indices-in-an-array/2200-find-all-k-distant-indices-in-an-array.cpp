class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        /*
        // find first key, then move index to check index - j
        // TC: O(n)
        // SC: O(1)
        int n = nums.size();
        vector<int> result;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (abs(i - j) <= k && nums[j] == key) {
                    result.push_back(i);
                    break;
                }
            }
        }
        return result;
        */
        // TC: O(n)
        // SC: O(n)
        int right = 0;
        int n = nums.size();
        vector<int> result;
        unordered_set<int> indices;
        while (right < n) {
            while (right < n && nums[right] != key) {
                right++;
            }

            // range: right - k ~ right + k
            int start = max(0, right - k);
            int end = min(right + k, n - 1);
            while (start <= end) {
                if (indices.count(start) < 1) {
                    indices.insert(start);
                    result.push_back(start);
                }
                start++;
            }
            right++;
        }
        return result;
    }
};