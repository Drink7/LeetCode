class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // divide to left and right part multiply sum
        // multiply the left and right part with the same index
        // TC: O(n)
        // SC: O(n)
        int n = nums.size();
        vector<int> leftPart(n);
        vector<int> rightPart(n);
        vector<int> result(n);
        // calculate left part
        leftPart[0] = 1;
        for (int i = 1; i < n; i++) {
            leftPart[i] = leftPart[i - 1] * nums[i - 1];
        }

        // calculate right part
        rightPart[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            rightPart[i] = rightPart[i + 1] * nums[i + 1];
        }

        // calculate result
        for (int i = 0; i < n; i++) {
            result[i] = leftPart[i] * rightPart[i];
        }
        return result;
    }
};