class Solution {
public:
    int maxLength(vector<string>& arr) {
        // brute force
        // TC: O(26*16*26)
        // SC: O(26*16*26)
        string path = "";
        int maxLen = 0;

        concatHelper(0, arr, path, maxLen);

        return maxLen;
    }

    void concatHelper(int start, vector<string>& arr, string path, int& maxLen) {
        // prune
        // need to check the path is valid or not
        bool letters[26] = {false};
        for (auto const& c : path) {
            int id = c - 'a';
            if (letters[id]) {
                return;
            }
            letters[id] = true;
        }

        if (start >= arr.size()) {
            maxLen = max(maxLen, (int)path.size());
            return;
        }

        // not choose next
        concatHelper(start + 1, arr, path, maxLen);

        // choose next
        concatHelper(start + 1, arr, path + arr[start], maxLen);
    }
};