class Solution {
public:
    bool isHappy(int n) {
        // use unordered_set to store calculated numbers
        unordered_set<int> happySet;
        while (n != 1) {
            n = digitHelper(n);
            if (happySet.count(n)) {
                return false;
            } else {
                happySet.insert(n);
            }
        }
        return true;
    }

    int digitHelper(int x) {
        int sum = 0;
        while (x != 0) {
            int remain = x % 10;
            x = x / 10;
            sum += remain * remain;
        }
        return sum;
    }
};