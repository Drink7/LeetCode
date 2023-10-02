class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        // hash set
        // TC: O(n)
        // SC: O(n)
        vector<int> result;
        unordered_set<int> numSet;
        for (auto const& num : nums) {
            if (numSet.count(num)) {
                result.push_back(num);
            }
            numSet.insert(num);
        }

        for (int i = 0; i < nums.size(); i++) {
            if (numSet.count(i + 1) < 1) {
                result.push_back(i + 1);
                break;
            }
        }
        return result;
    }
};