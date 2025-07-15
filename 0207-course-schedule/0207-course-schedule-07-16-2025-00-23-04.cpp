class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // topological sort
        // TC: O(V + E)
        // SC: O(V + E)
        // indegree
        // courseGraph
        vector<int> inDegree(numCourses, 0);
        unordered_map<int, vector<int>> adjList;

        // build empty list
        for (int i = 0; i < numCourses; i++) {
            adjList[i] = {};
        }

        // build adjacency list
        for (auto const& p : prerequisites) {
            int preCourse = p[1];
            int course = p[0];
            inDegree[course]++;
            adjList[preCourse].push_back(course);
        }

        // traverse, use queue to store initial inDegree = 0
        queue<int> q;
        vector<int> result;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                int course = q.front();
                q.pop();

                if (inDegree[course] == 0) {
                    result.push_back(course);
                }

                for (auto const& child : adjList[course]) {
                    inDegree[child]--;
                    if (inDegree[child] == 0) {
                        q.push(child);
                    }
                }             
            }
        }
        return result.size() == numCourses;
    }
};