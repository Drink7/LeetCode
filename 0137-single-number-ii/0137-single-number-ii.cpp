class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /*
        // hash table
        // TC: O(n)
        // SC: O(n)
        unordered_map<int, int> dict;
        for (auto const& num : nums) {
            dict[num]++;
        }

        for (auto const& p : dict) {
            if (p.second == 1) {
                return p.first;
            }
        }
        return -1;
        */

        /*
        // Math
        // TC: O(n)
        // SC: O(n)
        unordered_set<int> dict;
        int setSum = 0;
        int numSum = 0;
        for (auto const& num : nums) {
            dict.insert(num);
        }

        for (auto const& num : dict) {
            setSum += num;
        }

        for (auto const& num : nums) {
            numSum += num;
        }
        return (3 * setSum - numSum) / 2;
        */


        // Bit operation
        // TC: O(n)
        // SC: O(1)
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            int count = 0;
            for (int j = 0; j < nums.size(); j++) {
                if ((nums[j] >> i) & 1) {
                    count++;
                }
            }
            ans = ans | (count % 3) << i;
        }
        return ans;
        /*
        // Bit operation Magic
        // can not sort
        // TC: O(n)
        // SC: O(1)
        int ones = 0;
        int twos = 0;
        for (int i = 0; i < nums.size(); i++) {
            ones = (ones ^ nums[i]) & ~twos;
            twos = (twos ^ nums[i]) & ~ones;
        }
        return ones;
        */
    }
};