class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        /*
        // hash table and two loop traverse
        // TC: O(n^2)
        // SC: O(n)
        unordered_map<int, vector<int>> dict;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            dict[nums[i]].push_back(i);
        }

        // two loop traverse
        for (auto const& p : dict) {
            vector<int> indices = p.second;
            int indicesSize = indices.size();
            if (indicesSize > 1) {
                for (int j = indicesSize - 1; j > 0; j--) {
                    if (indices[j] - indices[j - 1] <= k) {
                        return true;
                    }
                }
            }
        }
        return false;
        */
        // Sliding window
        // TC: O(n)
        // SC: O(min(n, k))
        unordered_set<int> s;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i > k) {
                s.erase(nums[i - k - 1]);
            }
            if (s.count(nums[i])) {
                return true;
            } else {
                s.insert(nums[i]);
            }
        }
        return false;
    }
};