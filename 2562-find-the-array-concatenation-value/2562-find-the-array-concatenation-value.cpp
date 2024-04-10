class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        // two pointer head and tail
        // TC: O(n)
        // SC: O(1)
        int left = 0;
        int right = nums.size() - 1;
        long long result = 0;
        while (left <= right) {
            string concat = "";
            int concatInt = 0;
            if (left < right) {
                concat = to_string(nums[left]) + to_string(nums[right]);
            } else {
                concat = to_string(nums[left]);
            }
            concatInt = stoi(concat);
            result += concatInt;
            left++;
            right--;
        }
        return result;
    }
};