class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // topological sort
        // build adjancency list
        // indegree vector
        // start at each indegree
        // TC: O(E + V)
        // SC: O(E + V)
        unordered_map<int, vector<int>> adjList;
        vector<int> inDegree(numCourses, 0);

        for (auto const& edge : prerequisites) {
            adjList[edge[1]].push_back(edge[0]);
            inDegree[edge[0]]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }


        vector<int> courseList;
        while (q.size() > 0) {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                int course = q.front();
                q.pop();

                courseList.push_back(course);

                auto neighbors = adjList[course];
                for (auto const& neighbor : neighbors) {
                    inDegree[neighbor]--;
                    if (inDegree[neighbor] == 0) {
                        q.push(neighbor);
                    }
                }
            }
        }
        return courseList.size() == numCourses;
    }
};