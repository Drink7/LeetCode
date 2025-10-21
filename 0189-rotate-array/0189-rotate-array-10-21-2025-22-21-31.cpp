class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // reverse begin, end
        // reverse begin(), begin() + k
        // reverse begin() + k, end()
        // TC: O(n)
        // SC: O(1)
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};