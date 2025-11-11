class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // Kruskal's Algorithm + Union Find
        // TC: O(n^2)
        // SC: O(n^2)
        int n = points.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        parent.resize(n);
        rank.resize(n);
        // init
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }

        for (int i = 0; i < n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dist = abs(x1 - x2) + abs(y1 - y2);
                minHeap.push({dist, i, j});
            }
        }

        // start to build up mst
        // counter is to count if we have find n - 1 edges, we could prune to break  
        int counter = 0;
        int result = 0;
        while (minHeap.size() > 0 && counter < n - 1) {
            vector<int> heapTop = minHeap.top();
            minHeap.pop();
            int p1 = heapTop[1];
            int p2 = heapTop[2];
            if (findFunc(p1) != findFunc(p2)) {
                unionFunc(p1, p2);
                counter++;
                result += heapTop[0];
            }
        }
        return result;
    }

    int findFunc(int i) {
        if (parent[i] != i) {
            parent[i] = findFunc(parent[i]);
        }
        return parent[i];
    }

    void unionFunc(int i, int j) {
        int rootI = findFunc(i);
        int rootJ = findFunc(j);
        if (rootI == rootJ) {
            return;
        }

        if (rank[rootI] > rank[rootJ]) {
            parent[rootJ] = rootI;
        } else if (rank[rootI] < rank[rootJ]) {
            parent[rootI] = rootJ;
        } else {
            parent[rootJ] = rootI;
            rank[rootI]++;
        }
    }
private:
    vector<int> parent;
    vector<int> rank;
};