class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // store the p's letter count
        // use sliding window to check each string window
        // impossible when p length > s length
        // TC: O(mn) m is s length and n is p length
        // SC: O(1)
        vector<int> result;
        vector<int> pDict(26, 0);
        vector<int> windowDict(26, 0);
        for (int i = 0; i < p.size(); i++) {
            pDict[p[i] - 'a']++;
        }

        int left = 0;
        int right = 0;
        while (right < s.size()) {
            windowDict[s[right] - 'a']++;
            if (right - left + 1 >= p.size()) {
                if (isSame(windowDict, pDict)) {
                    result.push_back(left);
                }
                windowDict[s[left] - 'a']--;
                left++;
            }
            right++;
        }
        return result;
    }

    bool isSame(vector<int>& a, vector<int>& b) {
        if (a.size() != b.size()) {
            return false;
        }

        int n = a.size();
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }
};