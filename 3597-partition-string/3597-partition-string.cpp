class Solution {
public:
    vector<string> partitionString(string s) {
        // two pointers
        // if not seen, store left ~ right segment back to set
        // start with right + 1 again
        // TC: O(n)
        // SC: O(n)
        vector<string> result;
        unordered_set<string> strSet;
        int left = 0;
        int right = 0;
        int n = s.size();
        while (right < n) {
            string tmp = s.substr(left, right - left + 1);
            while (right < n && strSet.count(tmp) == 1) {
                right++;
                tmp = s.substr(left, right - left + 1);
            }

            if (strSet.count(tmp) == 0) {
                strSet.insert(tmp);
                result.push_back(tmp);
            }
            right++;
            left = right;
        }
        return result;
    }
};