class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // topological sort
        // TC: O(V + E)
        // SC: O(V + E)
        unordered_map<int, vector<int>> graph;
        vector<int> inDegree(numCourses, 0);

        // build graph
        for (auto const& prerequisite : prerequisites) {
            int preq = prerequisite[1];
            int cur = prerequisite[0];
            graph[preq].push_back(cur);
            inDegree[cur]++;
        }

        // bfs queue
        queue<int> q;
        int count = 0;

        // put unrelated
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                int course = q.front();
                q.pop();

                count++;

                for (int j = 0; j < graph[course].size(); j++) {
                    int next = graph[course][j];
                    inDegree[next]--;
                    if (inDegree[next] == 0) {
                        q.push(next);
                    }
                }
            }
        }
        return count == numCourses;
    }
};