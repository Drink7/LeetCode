class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // heap -> priority_queue (minHeap)
        // map -> store element, freq
        // freq into heap, and keep the heap with k size
        // TC: O(nlogn)
        // SC: O(k)
        unordered_map<int, int> freqDict;
        for (auto const& num : nums) {
            freqDict[num]++;
        }

        auto compare = [](pair<int, int>& p1, pair<int, int>& p2) { return p1.second > p2.second; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> pq(compare);

        for (auto const& p : freqDict) {
            pq.push(p);
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(pq.top().first);
            pq.pop();
        }
        return result;
    }
};