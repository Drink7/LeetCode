class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // use XOR
        // TC: O(n)
        // SC: O(1)
        // Solution 2: set (insert the set then erase the element in set)
        // Solution 3: 
        int base = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            base = base ^ nums[i];
        }
        return base;
    }
};