class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // use unordered_map to store freq
        // use max heap to store the pair<freq, string>
        // use our own compare
        // decltype
        // TC: O(nlogn)
        // SC: O(n)
        auto compare = [](pair<int, string>& p1, pair<int, string>& p2) {
            if (p1.first == p2.first) {
                return p1.second > p2.second;
            } else {
                return p1.first < p2.first;
            }
        };

        unordered_map<string, int> dict;
        for (auto const& word : words) {
            dict[word]++;
        }

        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(compare)> maxHeap;
        for (auto const& p : dict) {
            maxHeap.push({p.second, p.first});
        }

        vector<string> result;
        while (k > 0) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
            k--;
        }
        return result;
    }
};