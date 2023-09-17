class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // use map to store (val, index)
        // return the answer
        // TC: O(nlogn)
        // SC: O(1)
        vector<int> result;
        map<int, int> rankMap;
        for (int i = 0; i < arr.size(); i++) {
            rankMap[arr[i]] = i;
        }

        // map has been sorted, now traverse map to assign rank
        int rank = 1;
        for (auto const& p : rankMap) {
            rankMap[p.first] = rank;
            rank++;
        }

        // traverse arr again
        for (int i = 0; i < arr.size(); i++) {
            int val = arr[i];
            result.push_back(rankMap[val]);
        }
        return result;
    }
};