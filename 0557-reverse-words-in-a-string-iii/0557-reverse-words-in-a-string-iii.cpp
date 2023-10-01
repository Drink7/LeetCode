class Solution {
public:
    string reverseWords(string s) {
        // reverse each substring
        // TC: O(n^2)
        // SC: O(n)
        string result = "";
        stringstream ss(s);
        string token;
        while (ss >> token) {
            reverse(token.begin(), token.end());
            result = result + token + " ";
        }
        result.pop_back();
        return result;
    }
};