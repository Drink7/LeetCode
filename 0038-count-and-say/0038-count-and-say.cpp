class Solution {
public:
    string countAndSay(int n) {
        // Brute Force
        // TC: O(n^2)
        // SC: O(1)
        string result = "1";
        for (int i = 2; i <= n; i++) {
            // start from first char
            string tmp = "";
            int id = 0;
            int cnt = 0;
            char startChar = result[0];
            while (id < result.size()) {
                if (result[id] != startChar) {
                    tmp += to_string(cnt) + startChar;
                    startChar = result[id];
                    cnt = 1;
                } else {
                    cnt++;
                }

                if (id == result.size() - 1) {
                    tmp += to_string(cnt) + startChar;
                }

                id++;
            }
            result = tmp;
        }
        return result;
    }
};