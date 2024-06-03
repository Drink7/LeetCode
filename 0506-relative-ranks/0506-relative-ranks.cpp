class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        // Brute force
        // TC: O(nlogn)
        // SC: O(n)
        vector<int> copyScore(score.begin(), score.end());
        vector<string> result;
        unordered_map<int, int> dict;
        sort(copyScore.begin(), copyScore.end(), greater<int>());
        for (int i = 0; i < copyScore.size(); i++) {
            dict[copyScore[i]] = i;
        }

        for (auto const& num : score) {
            if (dict[num] == 0) {
                result.push_back("Gold Medal");
            } else if (dict[num] == 1) {
                result.push_back("Silver Medal");
            } else if (dict[num] == 2) {
                result.push_back("Bronze Medal");
            } else {
                result.push_back(to_string(dict[num] + 1));
            }
        }
        return result;
    }
};