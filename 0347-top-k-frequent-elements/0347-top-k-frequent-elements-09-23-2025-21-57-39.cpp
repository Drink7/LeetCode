class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // minHeap with size k
        // TC: O(n + nlogk)
        // SC: O(n + k)
        vector<int> result;
        unordered_map<int, int> dict;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for (auto const& num : nums) {
            dict[num]++;
        }

        for (auto const& p : dict) {
            minHeap.push({p.second, p.first});
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        for (int i = 0; i < k; i++) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;
    }
};