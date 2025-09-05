class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // prefix sum + hash map
        // TC: O(n)
        // SC: O(1)
        unordered_map<int, int> dict; // sum, index
        int sum = 0;
        int length = 0;
        dict[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                sum -= 1;
            } else {
                sum += 1;
            }

            if (dict.count(sum) < 1) {
                dict[sum] = i;
            } else {
                length = max(length, i - dict[sum]);
            }
        }
        return length;
    }
};