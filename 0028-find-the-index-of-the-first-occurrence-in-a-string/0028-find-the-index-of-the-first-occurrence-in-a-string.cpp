class Solution {
public:
    int strStr(string haystack, string needle) {
        // find api
        // TC: O(mn)
        // SC: O(1)
        if (haystack.size() < needle.size()) {
            return -1;
        }

        return (haystack.find(needle) == string::npos) ? -1 : haystack.find(needle);
    }
};