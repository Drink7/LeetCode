class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // heap -> priority_queue (minHeap)
        // map -> store element, freq
        // freq into heap, and keep the heap with k size
        unordered_map<int, int> freqDict;
        for (auto const& num : nums) {
            freqDict[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (auto const& p : freqDict) {
            pq.push({p.second, p.first});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};