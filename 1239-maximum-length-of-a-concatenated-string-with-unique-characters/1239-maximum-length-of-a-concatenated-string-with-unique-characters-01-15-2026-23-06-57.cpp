class Solution {
public:
    int maxLength(vector<string>& arr) {
        // brute force
        // TC: O(26*16*26)
        // SC: O(26*16*26)
        unordered_set<string> strSet;
        string path = "";
        concatHelper(0, arr, path, strSet);
        int maxLen = 0;

        // check valid
        for (auto const& str : strSet) {
            char letters[26] = {false};
            int cnt = 0;
            for (auto const& c : str) {
                int id = c - 'a';
                if (letters[id]) {
                    cnt = 0;
                    break;
                }
                letters[id] = true;
                cnt++;
            }
            maxLen = max(maxLen, cnt);
        }
        return maxLen;
    }

    void concatHelper(int start, vector<string>& arr, string path, unordered_set<string>& strSet) {
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