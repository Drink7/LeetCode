class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // count 1, stop when encounter 0
        // TC: O(n)
        // SC: O(1)
        int result = 0;
        int cnt = 0;
        for (auto const& num : nums) {
            if (num == 0) {
                result = max(result, cnt);
                cnt = 0;
            } else {
                cnt++;
            }
        }

        if (cnt != 0) result = max(result, cnt);
        return result;
    }
};