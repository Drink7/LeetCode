class Solution {
public:
    string minWindow(string s, string t) {
        // store t as an unorderd_map
        // traverse the s
        // use a count cnt to count the number we have hit (meet) for t
        // when number == 0, start shrink window
        // TC: O(m + n)
        // SC: O(m + n)
        int m = s.size();
        int n = t.size();

        if (n > m) {
            return "";
        }

        unordered_map<char, int> dict;

        for (auto const& c : t) {
            dict[c]++;
        }

        int cnt = n;
        int left = 0, right = 0;
        int startId = -1;
        int startSize = m + 1;
        while (right < m) {
            if (dict[s[right]] > 0) {
                // char met
                cnt--;
            }
            dict[s[right]]--;

            while (cnt == 0) {
                // start shrink window
                if (right - left + 1 < startSize) {
                    startSize = right - left + 1;
                    startId = left;
                }
                
                if (dict[s[left]] >= 0) {
                    cnt++;
                }
                dict[s[left]]++;
                left++;
            }
            right++;
        }

        if (startId == -1) {
            return "";
        } else {
            return s.substr(startId, startSize);
        }
    }
};