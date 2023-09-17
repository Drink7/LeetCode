class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // use map to store (val, index)
        // return the answer
        // TC: O(nlogn)
        // SC: O(n)
        vector<int> copyArr(arr);
        vector<int> result;
        unordered_map<int, int> rankMap;

        sort(copyArr.begin(), copyArr.end());
        for (int i = 0; i < copyArr.size(); i++) {
            int val = copyArr[i];
            if (rankMap.count(val) < 1) {
                rankMap[copyArr[i]] = rankMap.size() + 1;
            }
        }

        // traverse arr again
        for (int i = 0; i < arr.size(); i++) {
            int val = arr[i];
            result.push_back(rankMap[val]);
        }
        return result;
    }
};