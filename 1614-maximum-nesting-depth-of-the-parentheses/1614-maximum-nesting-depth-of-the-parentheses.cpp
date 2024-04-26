class Solution {
public:
    int maxDepth(string s) {
        // parentheses -> stack
        // find the maximum value of "(" stack
        // TC: O(n)
        // SC: O(1)
        int rightCnt = 0;
        int result = 0;
        int index = 0;
        int n = s.size();
        while (index < n) {
            if (s[index] == '(') {
                rightCnt++;
            } else if (s[index] == ')') {
                if (rightCnt > 0) {
                    rightCnt--;
                }
            }
            result = max(result, rightCnt);
            index++;
        }
        return result;
    }
};