class Solution {
public:
    int maximum69Number (int num) {
        // to string
        // left find first 6, right find first 9
        // switch and stoi is ans
        // TC: O(n)
        // SC: O(1)
        string numStr = to_string(num);
        int left = 0;
        int right = numStr.size() - 1;
        while (left <= right && numStr[left] != '6') {
            left++;
        }
        if (left <= right) {
            numStr[left] = '9';
        }
        return stoi(numStr);
    }
};