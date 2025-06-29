class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // max heap get top 2
        // TC: O(nlogn)
        // SC: O(n)
        priority_queue<int> pq;
        for (auto const& stone : stones) {
            pq.push(stone);
        }

        while (pq.size() > 1) {
            int top1 = pq.top();
            pq.pop();
            int top2 = pq.top();
            pq.pop();
            if (top1 != top2) {
                pq.push(top1 - top2);
            }
        }
        
        if (pq.size() == 0) {
            return 0;
        } else {
            return pq.top();
        }
    }
};