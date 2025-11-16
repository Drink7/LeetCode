class Solution {
public:
    int numSub(string s) {
        // sliding window
        // if (left != 1) left = right
        // if (right == 1) count the result
        // right++;
        // TC: O(n)
        // SC: O(1)
        /*
        int cnt = 0;
        int n = s.size();
        int left = 0, right = 0;
        while (right < n) {
            if (s[right] == '1') {
                if (s[left] == '0') {
                    left = right;
                }
                cnt = cnt % (1000000000 + 7);
                cnt += right - left + 1;
            } else {
                left = right;
            }
            right++;
        }
        return cnt;
        */
        int MOD = 1000000000 + 7;
        int result = 0, cur = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                cur++;
                result = (result + cur) % MOD;
            } else {
                cur = 0;
            }
        }
        return result;
    }
};