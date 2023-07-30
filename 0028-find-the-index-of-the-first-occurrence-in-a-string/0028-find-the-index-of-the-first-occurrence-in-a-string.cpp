class Solution {
public:
    int strStr(string haystack, string needle) {
        // Traverse two string
        // TC: O(m * n)
        // SC: O(1)
        if (needle.size() > haystack.size()) {
            return -1;
        }

        int m = haystack.size();
        int n = needle.size();
        for (int i = 0; i < m - n + 1; i++) {
            if (haystack[i] == needle[0]) {
                int j = 1;
                for (; j < n; j++) {
                    if (haystack[i + j] != needle[j]) {
                        break;
                    }
                }

                if (j == n) {
                    return i;
                }
            }
        }
        return -1;
    }
};