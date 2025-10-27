class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        // prefix sum + hash table
        // hash what?
        // capacity[left] = capacity[right]
        // capacity[l + 1] + ... capacity[right - 1] = prefix[right] - prefix[left + 1]
        // tuple left part
        // capacity[left] = capacity[right] 
        // capacity[left] = prefix[right] - prefix[left + 1]
        // capacity[left] + prefix[left + 1] = prefix[right] 

        map<pair<int, long long>, int> dict;
        int n = capacity.size();
        vector<long long> prefixSum(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i - 1] + capacity[i - 1];
        }

        long long cnt = 0;
        for (int i = 1; i < n; i++) {
            int capacityRight = capacity[i];
            long long prefixRight = prefixSum[i];
            cnt += dict[{capacityRight, prefixRight}];
            dict[{capacity[i - 1], capacity[i - 1] + prefixSum[i]}]++;
        }
        return cnt;
    }
};