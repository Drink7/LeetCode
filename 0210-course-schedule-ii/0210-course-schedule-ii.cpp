class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        /*
        vector<int> result;
        vector<int> visited(numCourses);
        used.resize(numCourses);
        // store edges
        for (int i = 0; i < prerequisites.size(); i++) {
            int curCourse = prerequisites[i][0];
            int preCourse = prerequisites[i][1];
            courseMap[curCourse].push_back(preCourse);
        }

        for (auto const& courses : courseMap) {
            int curCourse = courses.first;
            if (!dfs(result, visited, curCourse)) {
                return {};
            }
        }

        // check remaining courses
        for (int i = 0; i < numCourses; i++) {
            if (!used[i]) {
                result.push_back(i);
            }
        }
        return result;
        */

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
        return (sortedCourse.size() == numCourses) ? sortedCourse : vector<int>();
    }

    bool dfs(vector<int>& result, vector<int> visited, int curCourse) {
        // course used
        // current path used
        if (visited[curCourse]) {
            return false;
        }

        if (used[curCourse]) {
            return true;
        }

        if (courseMap.count(curCourse) < 1) {
            result.push_back(curCourse);
            used[curCourse] = true;
            return true;
        }

        visited[curCourse] = true;
        vector<int> preCourses = courseMap[curCourse];
        for (int i = 0; i < preCourses.size(); i++) {
            if (!dfs(result, visited, preCourses[i])) {
                return false;
            }
        }
        result.push_back(curCourse);
        used[curCourse] = true;

        // prune
        courseMap[curCourse] = {};
        return true;
    }
private:
    vector<bool> used;
    unordered_map<int, vector<int>> courseMap;
};