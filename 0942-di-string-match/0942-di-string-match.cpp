class Solution {
public:
    vector<int> diStringMatch(string s) {
        // use two pinter
        // fetch from 0 to s.size()
        // if s[i] == 'I', put left element
        // if s[i] == 'D', put right element
        // TC: O(n)
        // SC: O(1)
        int left = 0;
        int right = s.size();
        int index = 0;
        vector<int> result;
        while (left < right) {
            if (s[index] == 'I') {
                result.push_back(left);
                left++;
            } else {
                result.push_back(right);
                right--;
            }
            index++;
        }
        result.push_back(right);
        return result;
    }
};