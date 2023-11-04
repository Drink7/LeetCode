class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // TC: O(n)
        // SC: O(n)
        vector<int> rightArr;
        vector<int> leftArr;
        vector<int> result;
        int n = nums.size();

        rightArr.resize(n, 1);
        leftArr.resize(n, 1);

        // check left
        for (int i = 1; i < n; i++) {
            leftArr[i] = nums[i - 1] * leftArr[i - 1];
        }

        // check right
        for (int i = n - 1 - 1; i >= 0; i--) {
            rightArr[i] = nums[i + 1] * rightArr[i + 1];
        }

        // product
        for (int i = 0; i < n; i++) {
            result.push_back(leftArr[i] * rightArr[i]);
        }
        return result;
    }
};