class Solution {
public:
    bool isHappy(int n) {
        // Use Hash Table
        // set
        // TC: O(n)
        // SC: O(n)
        unordered_set<int> numSet;
        while (n != 1) {
            if (numSet.count(n)) {
                return false;
            } else {
                numSet.insert(n);
            }

            int sum = 0;
            while (n != 0) {
                int digit = n % 10;
                sum += digit * digit;
                n = n / 10;
            }
            n = sum;
        }
        return true;

        // Two Pointer

    }
};