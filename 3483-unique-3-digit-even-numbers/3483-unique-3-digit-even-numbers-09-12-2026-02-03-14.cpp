class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        // brute force to store all digit
        // TC: O(n!)
        // SC: O(n!)
        int n = digits.size();
        unordered_set<int> seen;

        for (int i = 0; i < n; i++) {
            if (digits[i] == 0) continue;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                for (int k = 0; k < n; k++) {
                    if (i == k || j == k) continue;
                    if (digits[k] % 2 != 0) continue;

                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    seen.insert(num);
                }
            }
        }
        return seen.size();
    }
};