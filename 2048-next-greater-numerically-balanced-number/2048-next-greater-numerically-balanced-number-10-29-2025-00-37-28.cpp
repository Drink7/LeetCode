class Solution {
public:
    int nextBeautifulNumber(int n) {
        // 0 ~ 10^6
        // 0 - 1224444
        // No 7, 8, 9
        // calculate digit freq of n, check the num > n
        // brute force?
        for (int i = n + 1; i <= 1224444; i++) {
            if (isValid(i)) {
                return i;
            }
        }
        return -1;
    }

    bool isValid(int n) {
        vector<int> freq(10, 0);
        while (n) {
            int num = n % 10;
            freq[num]++;
            n = n / 10;
        }

        for (int i = 0; i < 10; i++) {
            if (freq[i] > 0 && i != freq[i]) {
                return false;
            }
        }
        return true;
    }
};