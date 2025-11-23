class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        /*
        // sort
        // 2D LIS
        // TC: O(n^2)
        // SC: O(1)
        sort(envelopes.begin(), envelopes.end());
        int n = envelopes.size();
        vector<int> dp(n, 1);
        int maxLen = dp[0];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
        */
        sort(envelopes.begin(), envelopes.end(), [](auto const& a, auto const& b) {
            if (a[0] == b[0]) return a[1] > b[1]; 
            return a[0] < b[0];
        });
        int n = envelopes.size();
        vector<int> maxLis;
        for (auto const& env : envelopes) {
            int height = env[1];
            int left = 0;
            int right = maxLis.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (maxLis[mid] < height) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }

            if (left >= maxLis.size()) {
                maxLis.push_back(height);
            } else {
                maxLis[left] = height;
            }
        }
        return maxLis.size();
    }
};