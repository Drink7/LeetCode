class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        // use bitwise
        // 7-> 111 -> 4 2 1
        // 15 -> 1111
        // TC: O(n), n is queries length
        // SC: O(n)
        vector<int> powers;
        vector<int> result;
        int power = 1;
        while (n) {
            if (n & 1) {
                powers.push_back(power);
            }
            power = power << 1;
            n = n >> 1;
        }

        for (auto const& query : queries) {
            int left = query[0];
            int right = query[1];
            long long queryAns = powers[left];
            for (int i = left + 1; i <= right; i++) {
                queryAns = (queryAns * powers[i]) % (1000000007);
            }
            result.push_back(queryAns);
        }
        return result;
    }
};