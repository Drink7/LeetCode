class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // priority_queue
        // cycle = n + 1
        // TC: O(nlogn)
        // SC: O(n)
        int total = 0;
        int cycle = n + 1;
        priority_queue<int> pq;
        unordered_map<char, int> dict;

        for (auto const& task : tasks) {
            dict[task]++;
        }

        for (auto const& p : dict) {
            pq.push(p.second);
        }

        while (pq.size() > 0) {
            int time = 0;
            vector<int> tmp;
            for (int i = 0; i < cycle; i++) {
                if (pq.size() > 0) {
                    tmp.push_back(pq.top());
                    pq.pop();
                    time++;
                }
            }
            for (int& cnt : tmp) {
                cnt--;
                if (cnt > 0) {
                    pq.push(cnt);
                }
            }
            if (pq.size() > 0) {
                total += cycle;
            } else {
                total += time;
            }
        }
        return total;
    }
};