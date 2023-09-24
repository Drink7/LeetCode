class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // TC: O(nlogn)
        // SC: O(n)
        // unordered map store element, freq
        // priority_queue minHeap to keep k most
        unordered_map<int, int> freqDict;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (auto const& num : nums) {
            freqDict[num]++;
        }

        // push into pq
        for (auto const& p : freqDict) {
            pq.push({p.second, p.first});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        // output the result
        vector<int> result;
        for (int i = 0; i < k; i++) {
            pair<int, int> p = pq.top();
            pq.pop();
            result.push_back(p.second);
        }
        return result;
    }
};