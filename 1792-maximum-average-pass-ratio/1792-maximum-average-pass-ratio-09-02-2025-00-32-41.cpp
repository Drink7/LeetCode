class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        // maxHeap: pair<increase, index>
        priority_queue<pair<double,int>> pq;

        // 計算每個 class 初始的增益，放入 maxHeap
        for (int i = 0; i < n; i++) {
            double increase = (double)(classes[i][0]+1)/(classes[i][1]+1) - (double)classes[i][0]/classes[i][1];
            pq.push({increase, i});
        }

        while (extraStudents > 0) {
            auto top = pq.top(); pq.pop();
            int idx = top.second;

            // 將 extra student 分配到這個 class
            classes[idx][0] += 1;
            classes[idx][1] += 1;

            // 計算新的增益，再放回 heap
            double newIncrease = (double)(classes[idx][0]+1)/(classes[idx][1]+1) - (double)classes[idx][0]/classes[idx][1];
            pq.push({newIncrease, idx});

            extraStudents--;
        }

        // 計算平均通過率
        double result = 0;
        for (auto &c : classes) {
            result += (double)c[0]/c[1];
        }
        return result / n;
    }
};
