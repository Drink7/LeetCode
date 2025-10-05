class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visited;

        while (n != 1) {
            if (visited.count(n) > 0) {
                return false;
            }
            visited.insert(n);
            n = happyHelper(n);
        }
        return true;
    }

    int happyHelper(int x) {
        int result = 0;
        while (x) {
            int digit = x % 10;
            x = x / 10;
            result += pow(digit, 2);
        }
        return result;
    }
};