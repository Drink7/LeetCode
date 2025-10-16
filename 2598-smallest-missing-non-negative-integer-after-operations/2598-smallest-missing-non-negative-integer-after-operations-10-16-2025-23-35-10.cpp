class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        // % value, and find the result
        // TC: O(n)
        // SC: O(n)
        unordered_map<int, int> numMap;
        int result = 0;
        for (auto& num : nums) {
            if (num < 0) {
                num = num % value + value;
            }
            num = num % value;
            numMap[num]++;
        }

        while (numMap[result % value]) {
            numMap[result % value]--;
            result++;
        }
        return result;
    }
};