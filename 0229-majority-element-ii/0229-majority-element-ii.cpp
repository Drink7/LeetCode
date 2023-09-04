class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        /*
        // hash table
        // TC: O(n)
        // SC: O(n)
        unordered_map<int, int> dict;
        vector<int> result;
        for (auto const& num : nums) {
            dict[num]++;
        }

        for (auto const& p : dict) {
            if (p.second > nums.size() / 3) {
                result.push_back(p.first);
            }
        }
        return result;
        */
        // Similar to Majority Element but with two counter and candidate
        // TC: O(n)
        // SC: O(1)
        vector<int> result;
        int count1 = 0;
        int count2 = 0;
        int candidate1 = 0;
        int candidate2 = 1;
        for (auto const& num : nums) {
            if (num == candidate1) {
                count1++;
            } else if (num == candidate2) {
                count2++;
            } else {
                if (count1 == 0) {
                    candidate1 = num;
                    count1++;
                } else if (count2 == 0) {
                    candidate2 = num;
                    count2++;
                } else {
                    count1--;
                    count2--;
                }
            }
        }

        count1 = 0;
        count2 = 0;

        for (auto const& num : nums) {
            if (num == candidate1) {
                count1++;
            } else if (num == candidate2) {
                count2++;
            }
        }

        if (count1 > nums.size() / 3) {
            result.push_back(candidate1);
        }

        if (count2 > nums.size() / 3) {
            result.push_back(candidate2);
        }
        return result;
    }
};