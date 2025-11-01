class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // build adjacency list
        // build indegree arr
        // use a queue, start from indegree course which num is 0
        // store the queue pop result to a vector
        // check the vector size == numCourses, if not, return empty
        // TC: O(E + V)
        // SC: O(E + V)
        unordered_map<int, vector<int>> adjList;
        vector<int> indegree(numCourses + 1, 0);

        // build graph
        for (auto const& prerequisite : prerequisites) {
            adjList[prerequisite[1]].push_back(prerequisite[0]);
            indegree[prerequisite[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> result;
        // start the topological sort
        while (q.size() > 0) {
            int course = q.front(); q.pop();
            result.push_back(course);

            // traverse its neighbor
            for (auto const& neigh : adjList[course]) {
                indegree[neigh]--;
                if (indegree[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }
        if (result.size() == numCourses) {
            return result;
        } else {
            return {};
        }
    }
};