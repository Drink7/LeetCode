class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // unordered_map<string, int>
        // priority_queue<int, string>
        // TC: O(n + m log m), m different words, n words
        // SC: O(m)
        unordered_map<string, int> dict;
        vector<string> result;
        for (auto const& s : words) {
            dict[s]++;
        }

        auto cmp = [](const pair<int,string> &a, const pair<int,string> &b) {
            if (a.first == b.first) {
                return a.second > b.second;
            } else {
                return a.first < b.first;
            }
        };

        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> maxHeap;
        for (auto const& p : dict) {
            maxHeap.push({p.second, p.first});
        }

        for (int i = 0; i < k; i++) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return result;
    }
};