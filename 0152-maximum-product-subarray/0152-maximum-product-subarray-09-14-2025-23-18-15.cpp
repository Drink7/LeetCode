class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // TC: O(n)
        // SC: O(1)
        int maxProduct = 1;
        int minProduct = 1;
        int result = INT_MIN;
        for (auto const& num : nums) {
            if (num< 0) {
                swap(maxProduct, minProduct);
            }
            maxProduct = max(num, maxProduct * num);
            minProduct = min(num, minProduct * num);
            result = max(result, maxProduct);
        }
        return result;
    }
};