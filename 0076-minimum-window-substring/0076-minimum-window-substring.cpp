class Solution {
public:
    string minWindow(string s, string t) {
        // substring -> sliding window
        // if t size > s size -> false
        // smallest window size would be t size
        // save t to a unordered_map<char, int>
        // sliding window t
        // if the letters in t are not yet obtained, move right
        // if all letters in t are obtainbed, move left
        // TC: O(m + n)
        // SC: O(m + n)
        int m = s.size();
        int n = t.size();
        if (n > m) {
            return "";
        }

        unordered_map<char, int> t_dict;
        // store t to map
        for (auto const& c : t) {
            t_dict[c]++;
        }

        // traverse s
        int right = 0;
        int left = 0;
        int cnt = n;
        int result_left = 0;
        int result_len = 100001;
        while (right < m) {
            char s_right = s[right];
            //if (t_dict.count(s_right) > 0) {
                if (t_dict[s_right] > 0) {
                    cnt--;
                }
                t_dict[s_right]--;
            //}

            while (cnt == 0) {
                if (result_len > right - left + 1) {
                    result_len = right - left + 1;
                    result_left = left;
                }
                //if (t_dict.count(s[left]) > 0) {
                    if (t_dict[s[left]] >= 0) {
                        cnt++;
                    }
                    t_dict[s[left]]++;
                //}
                left++;
            }
            right++;
        }

        if (result_len == 100001) {
            return "";
        } else {
            return s.substr(result_left, result_len);
        }
    }
};