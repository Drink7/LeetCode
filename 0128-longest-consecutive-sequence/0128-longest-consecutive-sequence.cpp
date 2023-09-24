class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // can not sort
        // hash set, start with one element, two pointer forward backward
        // once found, count and remove from the set
        // TC: O(n)
        // SC: O(n)
        unordered_set<int> numSet;
        int result = 0;
        for (auto const& num : nums) {
            numSet.insert(num);
        }

        for (auto const& num : nums) {
            if (numSet.count(num)) {
                int cnt = 1;
                int base = num;
                while (numSet.count(base - 1)) {
                    cnt++;
                    base--;
                    numSet.erase(base);
                }

                base = num;
                while (numSet.count(base + 1)) {
                    cnt++;
                    base++;
                    numSet.erase(base);
                }

                result = max(result, cnt);
            }
        }
        return result;
    }
};