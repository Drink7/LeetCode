class Solution {
public:
    int maxLength(vector<string>& arr) {
        // brute force
        // TC: O(26*16*26)
        // SC: O(26*16*26)
        unordered_set<string> strSet;
        string path = "";
        int maxLen = 0;

        concatHelper(0, arr, path, strSet);

        // check valid
        for (auto const& str : strSet) {
            maxLen = max(maxLen, (int)str.size());
        }
        return maxLen;
    }

    void concatHelper(int start, vector<string>& arr, string path, unordered_set<string>& strSet) {
        // prune
        bool letters[26] = {false};
        for (auto const& c : path) {
            int id = c - 'a';
            if (letters[id]) {
                return;
            }
            letters[id] = true;
        }

        if (start >= arr.size()) {
            strSet.insert(path);
            return;
        }

        // not choose next
        concatHelper(start + 1, arr, path, strSet);

        // choose next
        concatHelper(start + 1, arr, path + arr[start], strSet);
    }
};