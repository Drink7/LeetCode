class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // hash map, int, int <num, freq>
        // heap <freq, num> with k size minHeap
        // TC: O(n)
        // SC: O(n)
        unordered_map<int, int> freq;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        vector<int> result;

        for (auto const& num : nums) {
            freq[num]++;
        }

        for (auto const& p : freq) {
            minHeap.push({p.second, p.first});

            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        while (minHeap.size() > 0) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return result;
    }
};