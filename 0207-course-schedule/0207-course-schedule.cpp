class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // topological sort
        // TC: O(V+E)
        // SC: O(V+E)
        unordered_map<int, int> inDegree;
        unordered_map<int, vector<int>> graph;
        int n = prerequisites.size();
        // init graph
        for (int i = 0; i < numCourses; i++) {
            graph[i] = {};
            inDegree[i] = 0;
        }

        // build graph
        for (int i = 0; i < n; i++) {
            int prev = prerequisites[i][1];
            int next = prerequisites[i][0];
            graph[prev].push_back(next);
            inDegree[next]++;
        }

        // build sequence
        vector<int> sortedCourses;
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        // traverse inDegree 0
        while (!q.empty()) {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                int course = q.front();
                q.pop();
                sortedCourses.push_back(course);

                // check next course
                for (int j = 0; j < graph[course].size(); j++) {
                    int next = graph[course][j];
                    inDegree[next]--;
                    if (inDegree[next] == 0) {
                        q.push(next);
                    }
                }
            }
        }
        return sortedCourses.size() == numCourses;
    }
};