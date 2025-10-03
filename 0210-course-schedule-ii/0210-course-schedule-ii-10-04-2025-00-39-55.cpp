class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // return course scheduler anwser
        // TC: O(E + V)
        // SC: O(E + V)
        unordered_map<int, vector<int>> adjList;
        vector<int> inDegree(numCourses, 0);
        for (auto const& edge : prerequisites) {
            adjList[edge[1]].push_back(edge[0]);
            inDegree[edge[0]]++;
        }

        queue<int> q; // sort
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> result;
        while(q.size() > 0) {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                int course = q.front();
                q.pop();

                result.push_back(course);
                for (auto const& neigh : adjList[course]) {
                    inDegree[neigh]--;
                    if (inDegree[neigh] == 0) {
                        q.push(neigh);
                    }
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