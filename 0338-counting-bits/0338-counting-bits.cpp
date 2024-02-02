class Solution {
public:
    vector<int> countBits(int n) {
        /*
        // log
        // TC: O(nlogn)
        // SC: O(1)
        vector<int> result;
        result.push_back(0);
        if (n == 0) {
            return result;
        }
        result.push_back(1);

        for (int i = 2; i <= n; i++) {
            int tmp = log2(i);
            int group = pow(2, tmp);

            int index = i % group;
            result.push_back(result[index] + 1);
        }
        return result;
        */
        vector<int> result;
        for (int i = 0; i <= n; i++) {
            int sum = 0;
            int tmp = i;
            while (tmp) {
                sum++;
                tmp = tmp & (tmp - 1);
            }
            result.push_back(sum);
        }
        return result;
    }
};