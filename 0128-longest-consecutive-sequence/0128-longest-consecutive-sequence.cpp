class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // store in unordered_set
        // count +1 and -1, and erase at the same time
        // check the longest result
        // TC: O(n)
        // SC: O(n)
        unordered_set<int> dict;
        for (auto const& num : nums) {
            dict.insert(num);
        }

        // find longest
        int result = 0;
        for (auto const& num : nums) {
            if (dict.count(num)) {
                int count = 1;
                int base = num;
                dict.erase(base);

                // start +1 / -1 find the longest
                // find +1
                while (dict.count(base + 1)) {
                    base++;
                    count++;
                    dict.erase(base);
                }

                // find -1
                base = num;
                while (dict.count(base - 1)) {
                    base--;
                    count++;
                    dict.erase(base);
                }
                result = max(result, count);
            }
        }
        return result;
    }
};