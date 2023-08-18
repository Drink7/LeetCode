class Solution {
public:
    bool isHappy(int n) {
        /*
        // Use Hash Table
        // set
        // TC: O(logn)
        // SC: O(logn)
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
        */

        // Two Pointer
        // Floyd's Cycle-Finding Algorithm.
        // TC: O(logn)
        // SC: O(1)
        int fast = n;
        int slow = n;
        fast = digitSum(fast);
        fast = digitSum(fast);
        slow = digitSum(slow);
        while (fast != slow) {
            fast = digitSum(fast);
            fast = digitSum(fast);
            slow = digitSum(slow);
        }

        if (slow == 1) {
            return true;
        } else {
            return false;
        }
    }

    int digitSum(int n) {
        int sum = 0;
        while (n != 0) {
            int digit = n % 10;
            sum += digit * digit;
            n = n / 10;
        }
        return sum;
    }
};