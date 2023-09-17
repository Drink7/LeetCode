class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        // hash set to store the candyType
        // the set size is answer
        unordered_set<int> candySet;
        for (auto const& type : candyType) {
            candySet.insert(type);
        }
        return min(candySet.size(), candyType.size() / 2);
    }
};