class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        // use two pointer, both start from the same position
        // left pointer goes left, right pointer goes right
        // TC: O(n^2)
        // SC: O(1)
        int n = s.size();
        vector<int> result;
        for (int i = 0; i < n; i++) {
            int left = i;
            int right = i;
            int cnt = 0;
            while (left >= 0 || right <= n - 1) {
                if ((left >= 0 && s[left] == c) || 
                    (right <= n - 1 && s[right] == c)) {
                    result.push_back(cnt);
                    break;
                } else {
                    cnt++;
                    left--;
                    right++;
                }
            }
        }
        return result;
    }
};