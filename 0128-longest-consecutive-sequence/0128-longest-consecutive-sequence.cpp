class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // use hashmap <int, bool>
        // find foward and backward
        // TC: O(n)
        // SC: O(n)
        unordered_map<int, bool> dict;
        int result = 0;
        for (auto const& num : nums) {
            dict[num] = false;
        }

        // traverse map
        for (auto p : dict) {
            int tmp = 0;
            if (p.second == false) {
                tmp++;
                p.second = true;

                // find foward
                int base = p.first;
                while (dict.count(base + 1) > 0 && dict[base + 1] == false) {
                    tmp++;
                    dict[base++] = true;
                }

                // find backward
                base = p.first;
                while (dict.count(base - 1) > 0 && dict[base - 1] == false) {
                    tmp++;
                    dict[base--] = true;
                }
            }

            if (tmp > result) {
                result = tmp;
            }
        }
        return result;
    }
};