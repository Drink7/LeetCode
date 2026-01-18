class Solution {
public:
    int punishmentNumber(int n) {
        // square num = i * i
        // square num to string, then palindrome and sum
        // if valid, store back to numDict
        int result = 0;

        for (int i = 1; i <= n; i++) {
            int square = i * i;
            if (isNumPunish(i, square)) {
                result += square;
            }
        }

        return result;
    }

    // num = 9
    // squareStr = 81
    bool isNumPunish(int num, int square) {
        int start = 0;
        bool valid = false;
        string squareStr = to_string(square);
        numHelper(squareStr, start, start, 0, num, valid);
        return valid;
    }

    // 1296
    // 100
    void numHelper(string& s, int start, int end, int sum, int& target, bool& valid) {
        if (valid) {
            return;
        }

        if (end == s.size() - 1) {
            int partNum = stoi(s.substr(start));
            if (sum + partNum == target) {
                valid |= true;
            }
            return;
        }

        // not split
        numHelper(s, start, end + 1, sum, target, valid);

        // split
        int partNum = stoi(s.substr(start, end - start + 1));
        numHelper(s, end + 1, end + 1, sum + partNum, target, valid);
    }
};