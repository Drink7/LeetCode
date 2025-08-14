class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // graph, order, dependency -> topological sort
        // TC: O(V + E)
        // SC: O(V + E)
        unordered_map<int, vector<int>> courseMap;
        vector<int> inDegree(numCourses, 0);
        for (auto const& course : prerequisites) {
            courseMap[course[1]].push_back(course[0]);
            inDegree[course[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        // start topological sort
        vector<int>  sorted;
        while (q.size() > 0) {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                auto course = q.front();
                q.pop();

                sorted.push_back(course);
                for (auto const& neigh : courseMap[course]) {
                    inDegree[neigh]--;
                    if (inDegree[neigh] == 0) {
                        q.push(neigh);
                    }
                }
            }
        }

        if (sorted.size() == numCourses) {
            return sorted;
        } else {
            return {};
        }
    }
};