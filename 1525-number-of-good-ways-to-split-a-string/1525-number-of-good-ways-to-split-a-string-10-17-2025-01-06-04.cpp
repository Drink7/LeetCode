class Solution {
public:
    int numSplits(string s) {
        // left part hash map
        // right part hash map
        // traverse, when i++, left part will insert s[i]
        // right part will erase s[i]
        // TC: O(n)
        // SC: O(n)
        unordered_map<char, int> left;
        unordered_map<char, int> right;

        // build set
        left[s[0]]++;
        for (int i = 1; i < s.size(); i++) {
            right[s[i]]++;
        }

        int cnt = 0;
        // check num split
        for (int i = 1; i < s.size(); i++) {
            if (left.size() == right.size()) {
                cnt++;
            }

            cout << left.size() << endl;
            cout << right.size() << endl;

            // insert s[i] into left
            left[s[i]]++;

            // remove s[i] out of right
            right[s[i]]--;

            if (right[s[i]] == 0) {
                right.erase(s[i]);
            }
        }
        return cnt;
    }
};