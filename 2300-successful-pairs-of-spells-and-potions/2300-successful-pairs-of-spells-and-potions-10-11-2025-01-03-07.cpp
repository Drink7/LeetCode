class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // spell can not sort
        // we only care about pairs, so sort the potions
        // find the first * spell[i] that larger or equal to success
        // count the pairs
        // TC: O(n * mlogm) 
        // SC: O(1)
        vector<int> result;
        sort(potions.begin(), potions.end());
        for (auto const& spell : spells) {
            int low = 0;
            int high = potions.size();
            while (low < high) {
                int mid = low + (high - low) / 2;
                if ((long long)spell * potions[mid] < success) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
            }

            // check low
            int pairs = (low < potions.size()) ? potions.size() - low : 0;
            result.push_back(pairs);
        }
        return result;
    }
};