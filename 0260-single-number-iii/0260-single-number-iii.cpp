class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // use XOR to find a^b
        // then, use num & (~(num - 1)) to find the first diff bit
        // make the original array only XOR the diff bit, we can get the first num
        // use the XOR result before to XOR the first num, get the second num
        // TC: O(n)
        // SC: O(1)
        long bitmask = 0;
        for (auto const& num : nums) {
            bitmask = num ^ bitmask;
        }

        // check the diff bit
        long diff = bitmask & (~bitmask + 1);
        int num1 = 0;
        int num2 = 0;
        for (auto const& num : nums) {
            if (num & diff) {
                num1 = num1 ^ num;
            }
        }
        num2 = num1 ^ bitmask;
        return {num1, num2};
    }
};