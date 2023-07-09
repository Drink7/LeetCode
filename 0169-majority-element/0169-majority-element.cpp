class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*
        // Hash table
        // TC: O(n)
        // SC: O(n)
        unordered_map<int, int> dict;
        int maxVal = 0;
        int maxCount = 0;
        for (auto const& num : nums) {
            dict[num]++;
        }

        for (auto const& p : dict) {
            if (p.second > maxCount) {
                maxCount = p.second;
                maxVal = p.first;
            }
        }
        return maxVal;
        */

        // Boyer-Moore Algo
        // TC: O(n)
        // SC: O(1)
        int current = 0;
        int counter = 0;
        for (auto const& num : nums) {
            if (counter == 0) {
                current = num;
                counter++;
            } else {
                if (current == num) {
                    counter++;
                } else {
                    counter--;
                }
            }
        }
        return current;
    }
};