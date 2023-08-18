class Solution {
public:
    bool isHappy(int n) {
        // Use Hash Map
        // TC: O(n)
        // SC: O(n)
        unordered_map<int, int> dict;
        while (n != 1) {
            if (dict.count(n)) {
                return false;
            }
            int key = n;
            int sum = 0;
            while (n != 0) {
                int digit = n % 10;
                sum += digit * digit;
                n = n / 10;
            }
            dict[key] = sum;
            n = sum;
        }
        return true;
    }
};