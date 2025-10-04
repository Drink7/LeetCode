class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // adjacency + priority_queue
        unordered_map<string, priority_queue<string, vector<string>, greater<>>> dict;
        vector<string> result;


        for (auto const& ticket : tickets) {
            dict[ticket[0]].push(ticket[1]);
        }

        dfs(dict, result, "JFK");
        reverse(result.begin(), result.end());
        return result;
    }

    void dfs(unordered_map<string, priority_queue<string, vector<string>, greater<>>>& dict, vector<string>& result, string cur) {
        auto& pq = dict[cur];
        while (pq.size() > 0) {
            string next = pq.top();
            pq.pop();
            dfs(dict, result, next);
        }
        result.push_back(cur);
    }
};