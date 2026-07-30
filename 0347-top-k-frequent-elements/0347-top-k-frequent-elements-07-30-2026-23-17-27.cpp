class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // store num into unordered_map<int, int> w/ element, cmt
        // store the pair, (cnt, element) to a minHeap
        // keep the heap to k size
        // pop out all the heap and store to the result
        // TC: O(nlogn)
        // SC: O(n)
        unordered_map<int, int> dict;
        for (auto const& num : nums) {
            dict[num]++;
        }

        // store into a minHeap
        priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> pq;
        for (auto const& [num, cnt] : dict) {
            pq.push({cnt, num});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> result;
        for (int i = 0; i < k; i++) {
            auto [cnt, num] = pq.top();
            pq.pop();
            result.push_back(num);
        }
        return result;
    }
};