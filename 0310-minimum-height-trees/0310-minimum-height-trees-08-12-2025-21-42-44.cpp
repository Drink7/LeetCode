class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        /*
        // BFS with visited
        // TC: O(V + E)
        // SC: O(V + E)
        unordered_map<int, vector<int>> adjList;
        vector<bool> visited(n, false);
        unordered_map<int, vector<int>> heightMap;
        int minValue = INT_MAX;

        // build graph
        // undirected weight graph
        for (auto const& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        // traverse each nodes
        for (int i = 0; i < n; i++) {
            fill(visited.begin(), visited.end(), false);
            queue<int> q;
            int height = 0;
            int visitCnt = n - 1;
            q.push(i);
            visited[i] = true;

            while (q.size() > 0 && visitCnt > 0) {
                int qSize = q.size();
                for (int j = 0; j < qSize; j++) {
                    auto node = q.front();
                    q.pop();
                    for (auto const& neighbor : adjList[node]) {
                        if (visited[neighbor] != true) {
                            q.push(neighbor);
                            visited[neighbor] = true;
                            visitCnt--;
                        }
                    }
                }
                height++;
            }

            if (height < minValue) {
                minValue = height;
            }
            heightMap[height].push_back(i);
        }
        return heightMap[minValue];
        */

        // topological sort
        // Check we sorted count
        // TC: O(V + E)
        // SC: O(V + E)
        if (n == 1) {
            return {0};
        }
        unordered_map<int, vector<int>> adjList;
        vector<int> inDegree(n, 0);
        // build graph
        // undirected weight graph
        for (auto const& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
            inDegree[edge[0]]++;
            inDegree[edge[1]]++;
        }

        // start with inDegree is 1
        queue<int> q;
        int visitCnt = n;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 1) {
                q.push(i);
                visitCnt--;
            }
        }

        int minValue = 0;
        while (q.size() > 0 && visitCnt > 0) {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                auto node = q.front();
                q.pop();
                for (auto const& neighbor : adjList[node]) {
                    inDegree[neighbor]--;
                    if (inDegree[neighbor] == 1) {
                        q.push(neighbor);
                        visitCnt--;
                    }
                }
            }
            minValue++;
        }
        vector<int> result;
        while (q.size() > 0) {
            result.push_back(q.front());
            q.pop();
        }

        return result;
    }
};