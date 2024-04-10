class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        // two array to store odd and even, then store in result
        // TC: O(n)
        // SC: O(n)
        vector<int> odd;
        vector<int> even;
        vector<int> result;
        for (auto const& num : nums) {
            if (num % 2 == 0) {
                even.push_back(num);
            } else {
                odd.push_back(num);
            }
        }

        int n = nums.size();
        int oddId = 0;
        int evenId = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                result.push_back(even[evenId++]);
            } else {
                result.push_back(odd[oddId++]);
            }
        }
        return result;
    }
};