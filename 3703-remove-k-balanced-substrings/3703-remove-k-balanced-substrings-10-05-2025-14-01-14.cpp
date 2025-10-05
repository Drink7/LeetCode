class Solution {
public:
    string removeSubstring(string s, int k) {
        // stack concept
        // TC: O(n)
        // SC: O(n)
        string result = "";
        for (auto const& c : s) {
            result += c;

            // check pattern
            int resultSize = result.size();
            if (resultSize >= k * 2) {
                bool isPattern = true;
                int checkStart = resultSize - 1 - (k * 2 - 1);
                int checkEnd = resultSize - 1;
                for (int i = checkEnd; i > checkEnd - k; i--) {
                    if (result[i] != ')') {
                        isPattern = false;
                        break;
                    }
                }

                for (int i = checkEnd - k; i >= checkStart; i--) {
                    if (result[i] != '(') {
                        isPattern = false;
                        break;
                    }
                }

                if (isPattern) {
                    result.erase(checkStart, checkEnd + 1);
                }
            }
        }
        return result;
    }
};
