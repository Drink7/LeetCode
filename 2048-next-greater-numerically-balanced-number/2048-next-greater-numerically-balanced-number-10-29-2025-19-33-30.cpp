class Solution {
public:
    int nextBeautifulNumber(int n) {
        /*
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
        */
        vector<int> all;
        vector<int> count(10, 0);
        dfs(all, count, 0);
        sort(all.begin(), all.end());
        for (auto const& num : all) {
            if (num > n) {
                return num;
            }
        }
        return -1;
    }

    void dfs(vector<int>& all, vector<int>& count, int num) {
        if (num > 1666666) {
            return;
        }

        if (num > 0 && isValid(count)) {
            all.push_back(num);
        }

        num = num * 10;

        for(int i = 1; i < 7; i++) {
            num += i;
            count[i]++;
            dfs(all, count, num);
            count[i]--;
            num -= i;
        }
    }

    bool isValid(vector<int>& count) {
        for (int i = 1; i < 7; i++) {
            if (count[i] > 0 && i != count[i]) return false;
        }
        return true;
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