class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // store the p's letter count
        // use sliding window to check each string window
        //impossible when p length > s length
        // TC: O(mn) m is s length and n is p length
        // SC: O(1)
        vector<int> result;
        vector<int> pDict(26, 0);
        for (auto const& c : p) {
            pDict[c - 'a']++;
        }

        int m = s.size();
        int n = p.size();

        int left = 0;
        int right = n - 1;
        while (right < m) {
            vector<int> copyDict(pDict);
            bool isFind = true;
            for (int i = left; i <= right; i++) {
                char c = s[i];
                if (copyDict[c - 'a'] == 0) {
                    isFind = false;
                    break;
                }
                copyDict[c - 'a']--;
            }
            if (isFind) {
                result.push_back(left);
            }
            left++;
            right++;
        }
        return result;
    }
};