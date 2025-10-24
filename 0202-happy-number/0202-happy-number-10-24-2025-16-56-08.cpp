class Solution {
public:
    bool isHappy(int n) {
        // calculate the result of n and the its next
        // check cycle
        int slow = n;
        int fast = n;
        while (helper(fast) != 1 && helper(helper(fast)) != 1) {
            slow = helper(slow);
            fast = helper(helper(fast));

            if (slow == fast) {
                return false;
            }
        }
        return true;
    }

    int helper(int n) {
        int sum = 0;
        while (n) {
            sum += pow(n % 10, 2);
            n = n / 10;
        }
        return sum;
    }
};