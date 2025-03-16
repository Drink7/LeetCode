class Solution {
public:
    int numberOfSubstrings(string s) {
        // find the first substring
        // if found, add string size - right
        // move left, find next first substring
        // until right == string size
        // TC: O(n)
        // SC: O(1)
        int left = 0, right = 0;
        int n = s.size();
        int result = 0;
        int cnt = 3;
        int cntArr[3] = {1, 1, 1};
        while (right < n) {
            cntArr[s[right] - 'a']--;
            if (cntArr[s[right] - 'a'] == 0) {
                cnt--;
            }

            while (cnt == 0) {
                result += n - right;

                // move left
                cntArr[s[left] - 'a']++;
                if (cntArr[s[left] - 'a'] > 0) {
                    cnt++;
                }
                left++;
            }
            right++;
        }
        return result;
    }
};