class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        // build prefix sum
        // TC: O(n)
        // SC: O(1)

        int sum = 0;
        int result = 0;
        for (auto const& num : gain) {
            sum += num;
            result = max(sum, result);
        }
        return result;
    }
};