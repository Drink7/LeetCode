class Solution {
public:
    int lengthOfLastWord(string s) {
        // Word split and find the n - 1 part
        // return its length
        // TC: O(n)
        // SC: O(1)
        stringstream ss(s);
        string token;

        while (ss >> token);

        return token.size();
    }
};