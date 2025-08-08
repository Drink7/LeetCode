class Solution {
public:
    bool isHappy(int n) {
        /*
        // set to store the answer
        // if loop, must not be happy
        // TC: O(n)
        // SC: O(n)
        unordered_set<int> dict;
        while (n != 1) {
            if (dict.count(n) > 0) {
                return false;
            }

            dict.insert(n);

            int sum = 0;
            while (n > 0) {
                int remain = n % 10;
                sum += remain * remain;
                n = n / 10;
            }
            n = sum;
        }
        return true;
        */

        // Fast-slow pointer
        // TC: O(logn)
        // SC: O(logn)
        int fast = sumOfSquare(n);
        int slow = fast;
        fast = sumOfSquare(fast);

        while (fast != slow) {
            fast = sumOfSquare(fast);
            fast = sumOfSquare(fast);
            slow = sumOfSquare(slow);
        }
        return fast == 1;
    }

    int sumOfSquare(int n) {
        int sum = 0;
        while (n > 0) {
            int remain = n % 10;
            sum += remain * remain;
            n = n / 10;
        }
        return sum;
    }
};