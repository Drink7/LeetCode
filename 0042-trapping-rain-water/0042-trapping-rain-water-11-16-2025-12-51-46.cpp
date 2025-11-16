class Solution {
public:
    int trap(vector<int>& height) {
        // two pointers
        // pre_max > suf_max, ans += suf_max - height[right], move right
        // else, move left
        // TC: O(n)
        // SC: O(1)
        int left = 0, right = height.size() - 1;
        int pre_max = height[left], suf_max = height[right];
        int ans = 0;
        while (left < right) {
            pre_max = max(pre_max, height[left]);
            suf_max = max(suf_max, height[right]);
            if (pre_max > suf_max) {
                ans += suf_max - height[right];
                right--;
            } else {
                ans += pre_max - height[left];
                left++;
            }
        }
        return ans;
    }
};