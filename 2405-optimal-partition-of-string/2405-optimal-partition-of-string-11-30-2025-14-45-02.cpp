class Solution {
public:
    int partitionString(string s) {
        // use hash set to check char is unique
        // sliding window maintain a set
        // TC: O(n)
        // SC: O(n)
        unordered_set<char> charSet;
        int cnt = 0;
        int left = 0, right = 0, n = s.size();
        while (right < n) {
            if (charSet.count(s[right])) {
                cnt++;
                while (left < right) {
                    charSet.erase(s[left]);
                    left++;
                }
            }
            charSet.insert(s[right]);
            right++;
        }
        return cnt + 1;
    }
};