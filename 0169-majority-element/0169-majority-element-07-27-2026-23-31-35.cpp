class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // mark the one as majority if cnt = 1, then go next
        // if next one is the same value, cnt++
        // not the same, cnt--
        // TC: O(n)
        // SC: O(1)
        int ans = 0;
        int cnt = 0;
        for (auto const& num : nums) {
            if (cnt == 0) {
                ans = num;
                cnt = 1;
            } else {
                if (num == ans) {
                    cnt++;
                } else {
                    cnt--;
                }
            }
        }
        return ans;
    }
};