class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // topological sort
        // TC: O(V+E)
        // SC: O(E)
        vector<int> inDegree(numCourses, 0);
        unordered_map<int, vector<int>> adjacencyMap;
        for (int i = 0; i < numCourses; i++) {
            adjacencyMap[i] = {};
        }

        // Build the graph
        for (int i = 0; i < prerequisites.size(); i++) {
            int preq = prerequisites[i][1];
            int course = prerequisites[i][0];
            adjacencyMap[preq].push_back(course);
            inDegree[course]++;
        }

        // Start to sort
        queue<int> sortQ;
        vector<int> sortedCourses;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                sortQ.push(i);
            }
        }

        while (!sortQ.empty()) {
            int course = sortQ.front();
            sortQ.pop();

            if (inDegree[course] == 0) {
                sortedCourses.push_back(course);
            }

            for (int i = 0; i < adjacencyMap[course].size(); i++) {
                int nextCourse = adjacencyMap[course][i];
                inDegree[nextCourse]--;
                if (inDegree[nextCourse] == 0) {
                    sortQ.push(nextCourse);
                }
            }
        }
        return sortedCourses.size() == numCourses;
    }
};