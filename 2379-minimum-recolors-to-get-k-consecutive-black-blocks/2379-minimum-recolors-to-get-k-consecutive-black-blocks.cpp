class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        // simple sliding window
        // TC: O(n)
        // SC: O(1)
        int left = 0;
        int right = left;
        int n = blocks.size();
        int result = n;
        int wCnt = 0;
        while (right < n) {
            if (blocks[right] == 'W') {
                wCnt++;
            }
            if (right - left + 1 == k) {
                result = min(result, wCnt);
                if (blocks[left] == 'W') {
                    wCnt--;
                }
                left++;
            }
            right++;
        }
        return result;
    }
};