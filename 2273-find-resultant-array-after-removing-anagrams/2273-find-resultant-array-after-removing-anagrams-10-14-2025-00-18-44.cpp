class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        // two pointers
        // left is the last distinct word
        // right keep going
        // if words[right] == words[left], right++
        // if words[right] != words[left], left = right
        // TC: O(n * mlogm)
        // SC: O(1)
        int left = 0;
        int right = 0;
        int n = words.size();
        vector<string> result;
        while (right < n) {
            if (result.empty()) {
                result.push_back(words[right]);
            } else {
                string leftStr = words[left];
                string rightStr = words[right];
                sort(leftStr.begin(), leftStr.end());
                sort(rightStr.begin(), rightStr.end());
                if (leftStr != rightStr) {
                    result.push_back(words[right]);
                    left = right;
                }
            }
            right++;
        }
        return result;
    }
};