class Solution {
public:
    int titleToNumber(string columnTitle) {
        // traverse and cacluate
        // TC: O(n)
        // SC: O(1)
        int n = columnTitle.size();
        int num = 0;
        for (int i = 0; i < n; i++) {
            char c = columnTitle[i];
            num *= 26;
            num += (c - 'A') + 1;
        }
        return num;
    }
};