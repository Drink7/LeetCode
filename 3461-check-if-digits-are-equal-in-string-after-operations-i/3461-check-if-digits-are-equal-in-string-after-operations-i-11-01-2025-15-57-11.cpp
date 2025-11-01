class Solution {
public:
    bool hasSameDigits(string s) {
        // until s.size() == 2
        // keep calculate
        // check final s[0] == s[1]?
        // TC: O(n!)
        // SC: O(1)
        while (s.size() > 2) {
            string tmp = "";
            int n = s.size();
            for (int i = 0; i < n - 1; i++) {
                tmp += to_string(((s[i] - '0') + (s[i + 1] - '0')) % 10);
            }
            s = tmp;
        }
        return s[0] == s[1];
    }
};