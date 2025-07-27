class Solution {
public:
    void sortColors(vector<int>& nums) {
        // no sort
        // dutch flags
        // TC: O(n)
        // SC: O(n)
        // map can solve
        map<int, int> dict;
        for (auto const& num : nums) {
            dict[num]++;
        }

        int index = 0;
        for (auto const& p : dict) {
            int colorSize = p.second;
            for (int i = 0; i < colorSize; i++) {
                nums[index++] = p.first;
            }
        }
    }
};