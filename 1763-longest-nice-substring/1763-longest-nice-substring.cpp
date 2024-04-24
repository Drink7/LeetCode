class Solution {
public:
    string longestNiceSubstring(string s) {
        /*
        // brute force
        // TC: O(n^2)
        // SC: O(n)
        int n = s.size();
        int maxLength = 0;
        string result = "";
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isNiceStr(s, i, j)) {
                    if (j - i + 1 > maxLength) {
                        maxLength = j - i + 1;
                        result = s.substr(i, j - i + 1);
                    }
                }
            }
        }
        return result;
    }

    bool isNiceStr(string& s, int left, int right) {
        unordered_map<char, bool> dict;
        bool isNice = true;
        for (int i = left; i <= right; i++) {
            dict[s[i]] = true;
        }

        while (left <= right) {
            if (islower(s[left])) {
                if (dict.count(toupper(s[left])) < 1) {
                    return false;
                }
            } else {
                if (dict.count(tolower(s[left])) < 1) {
                    return false;
                }
            }
            left++;
        }
        return true;
        
    }

    */
        // divide and conquer
        if (s.size() < 2) {
            return "";
        }

        unordered_set<char> dict;
        for (auto const& c : s) {
            dict.insert(c);
        }

        for (int i = 0; i < s.size(); i++) {
            if (dict.count(tolower(s[i])) && dict.count(toupper(s[i]))) {
                continue;
            }

            string str1 = longestNiceSubstring(s.substr(0, i));
            string str2 = longestNiceSubstring(s.substr(i + 1));

            // we return the earliset nice
            if (str1.size() >= str2.size()) {
                return str1;
            } else {
                return str2;
            }
        }

        // whole string is nice
        return s;
    }
};