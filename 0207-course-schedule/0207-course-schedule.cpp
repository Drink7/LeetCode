class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        /*
        vector<bool> visited(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            int curCourse = prerequisites[i][0];
            int preCourse = prerequisites[i][1];
            courseMap[curCourse].push_back(preCourse);
        }

        for (auto const& course : courseMap) {
            int curCourse = course.first;
            if (!dfs(visited, curCourse)) {
                return false;
            }
        }
        return true;
        */
        // Init the graph
        vector<int> inDegree(numCourses, 0);
        unordered_map<int, vector<int>> graph;
        for(int i = 0; i < numCourses; ++i) {
            inDegree[i] = 0;
            graph[i] = {};
        }

        // Build the graph
        for(int i = 0; i < prerequisites.size(); ++i) {
            int prereq = prerequisites[i][1];
            int course = prerequisites[i][0];

            graph[prereq].push_back(course);
            inDegree[course]++;
        }

        // Find all sources
        queue<int> sources;
        for(int i = 0; i < numCourses; i++) {
            if(inDegree[i] == 0) {
                sources.push(i);
            }
        }

        // Build the sorted order
        vector<int> sortedCourse;
        while(!sources.empty()) {
            int course = sources.front();
            sources.pop();

            sortedCourse.push_back(course);

            for(auto& child: graph[course]) {
                if(--inDegree[child] == 0) {
                    sources.push(child);
                }
            }
        }

        // If the size of topological order list is not equal to numCourses
        // Return false
        return sortedCourse.size() == numCourses;
    }

    bool dfs(vector<bool>& visited, int course) {
        // No prerequisite
        if (courseMap.count(course) < 1) {
            return true;
        }

        if (visited[course]) {
            return false;
        }

        visited[course] = true;
        vector<int> preCourses = courseMap[course];
        int isFinish = true;
        for (int i = 0; i < preCourses.size(); i++) {
            isFinish = isFinish && dfs(visited, preCourses[i]);
        }
        // prune
        courseMap[course] = {};
        visited[course] = false;
        return isFinish;
    }

private:
    unordered_map<int, vector<int>> courseMap;
};