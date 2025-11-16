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
        long long result = 0;
        int prevCnt = 0;
        int n = s.size(), index = 0;
        while (index < n) {
            long long onesCnt = 0;
            while (s[index] == '1') {
                onesCnt++;
                index++;
            }
            result = result % MOD;
            result += onesCnt * (onesCnt + 1) / 2;
            index++;
        }
        return result;
    }
};