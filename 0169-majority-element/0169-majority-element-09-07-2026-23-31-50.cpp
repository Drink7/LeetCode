class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // map store and find max
        // TC: O(n) / SC: O(n)
        // majority count > n/2
        // if we use +1 for same number, and -1 for diff num
        // when count = 0 and the next number would be majority
        // not possible: 3 3 2 2 1
        // 3 3 3 2 1
        // TC: O(n)
        // SC: O(1)
        int cur = 0;
        int cnt = 0;
        for (auto const& num : nums) {
            if (cnt == 0) {
                cur = num;
                cnt++;
            } else {
                if (num != cur) {
                    cnt--;
                } else {
                    cnt++;
                }
            }
        }
        return cur;
    }
};