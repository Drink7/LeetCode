class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        // Note: The inputs will be generated such that there exists a valid arrangement of pairs.
        // Must be a Euler path
        unordered_map<int, queue<int>> adjList;
        unordered_map<int, int> inDegree;
        unordered_map<int, int> outDegree;
        vector<vector<int>> result;
        for (auto const& pair : pairs) {
            int start = pair[0];
            int end = pair[1];
            adjList[start].push(end);
            outDegree[start]++;
            inDegree[end]++;
        }

        // find start, check euler path or euler circuit
        int start = 0;
        bool isCircuit = true;
        for (auto const& p : adjList) {
            if (outDegree[p.first] != inDegree[p.first]) {
                isCircuit = false;
                break;
            } else {
                start = p.first;
            }
        }

        if (!isCircuit) {
            for (auto const& p : adjList) {
                if (outDegree[p.first] == inDegree[p.first] + 1) {
                    start = p.first;
                    break;
                }
            }
        }

        dfs(adjList, result, start);
        reverse(result.begin(), result.end());
        return result;
    }

    void dfs(unordered_map<int, queue<int>>& adjList, vector<vector<int>>& result, int cur) {
        auto& q = adjList[cur];
        while (q.size() > 0) {
            auto end = q.front();
            q.pop();
            dfs(adjList, result, end);
            result.push_back({cur, end});
        }
    }
};