class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // binary search
        // sort potions
        // traverse spells, for each spell, find spell * potion >= success (the first >=)
        // if index >= potions.size(), no pairs
        // else potions.size() - index are all the pairs
        // TC: O(m + nlogn), m is spells size, n is potions size
        // SC: O(1)
        vector<int> result;
        sort(potions.begin(), potions.end());
        for (auto const& spell : spells) {
            int left = 0;
            int right = potions.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if ((long long)spell * potions[mid] < success) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            if (left == potions.size()) {
                result.push_back(0);
            } else {
                result.push_back(potions.size() - left);
            }
        }
        return result;
    }
};