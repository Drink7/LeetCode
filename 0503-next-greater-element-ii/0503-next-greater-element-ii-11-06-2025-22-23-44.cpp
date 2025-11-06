class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // 1 2 1 1 2 1
        // 1 2 3 4 3 1 2 3 4 3
        // circular -> concat two nums
        // TC: O(n)
        // SC: O(n)
        int n = nums.size();
        nums.insert(nums.end(), nums.begin(), nums.end());
        int newN = nums.size();
        vector<int> result(newN, -1);
        stack<int> stk;
        for (int i = 0; i < newN; i++) {
            while (!stk.empty() && nums[stk.top()] < nums[i]) {
                result[stk.top()] = nums[i];
                stk.pop();
            }
            stk.push(i);
        }

        result.resize(n);
        return result;
    }
};