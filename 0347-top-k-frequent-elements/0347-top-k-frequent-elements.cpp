class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // store the number to map
        // store freq number in min heap
        // pop all pair in heap for result
        // return result
        // TC: O(nlogn)
        // SC: O(n)
        unordered_map<int, int> dict;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> result;
        for (auto const& num : nums) {
            dict[num]++;
        }

        // store in min heap
        for (auto const& p : dict) {
            pq.push({p.second, p.first});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        for (int i = 0; i < k; i++) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};