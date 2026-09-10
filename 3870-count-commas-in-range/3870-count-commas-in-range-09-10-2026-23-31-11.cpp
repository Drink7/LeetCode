class Solution {
public:
    int countCommas(int n) {
        // every 3 digits insert 1 comma
        // if (n - 1000 > 0)
        // num = n - 1000
        // cnt += (num + 1)
        // else
        // return
        int cnt = 0;
        if (n - 1000 >= 0) {
            int num = n - 1000;
            cnt += (num + 1);
        }
        return cnt;
    }
};