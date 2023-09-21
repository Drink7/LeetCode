class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // topological sort
        // TC: O(V + E)
        // SC: O(V + E)
        vector<int> inDegree(numCourses, 0);
        unordered_map<int, vector<int>> graph;

        // build graph
        for (int i = 0; i < prerequisites.size(); i++) {
            int preq = prerequisites[i][1];
            int cur = prerequisites[i][0];
            graph[preq].push_back(cur);
            inDegree[cur]++;
        }

        // Find all sources
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> sortedCourse;
        while (!q.empty()) {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                int course = q.front();
                q.pop();

                sortedCourse.push_back(course);

                for (int j = 0; j < graph[course].size(); j++) {
                    int next = graph[course][j];
                    inDegree[next]--;
                    if (inDegree[next] == 0) {
                        q.push(next);
                    }
                }
            }
        }
        return sortedCourse.size() == numCourses;
    }
};