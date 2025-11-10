class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        /*
        // calculate base prefix sum
        // sort
        // sum from index left - 1 to right - 1
        // TC: O(n^2logn)
        // SC: O(n^2)
        int modulo = 1000000007;
        vector<int> prefixSum(nums.begin(), nums.end());
        for (int i = 1; i < n; i++) {
            prefixSum[i] = (prefixSum[i] + prefixSum[i - 1]) % modulo;
        }

        // calculate all subarray
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                prefixSum.push_back(prefixSum[j] - prefixSum[i]);
            }
        }

        sort(prefixSum.begin(), prefixSum.end());

        int result = 0;
        for (int i = left - 1; i <= right - 1; i++) {
            result = (result + prefixSum[i]) % modulo;
        }
        return result;
        */
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for (int i = 0; i < n; i++) {
            minHeap.push({nums[i], i});
        }

        int ans = 0;
        int mod = 1e9 + 7;

        for (int i = 1; i <= right; i++) {
            auto p = minHeap.top();
            minHeap.pop();

            if (i >= left) {
                ans = (ans + p.first) % mod;
            }

            if (p.second < n - 1) {
                p.second++;
                p.first += nums[p.second];
                minHeap.push(p);
            }
        }
        return ans;

    }
};