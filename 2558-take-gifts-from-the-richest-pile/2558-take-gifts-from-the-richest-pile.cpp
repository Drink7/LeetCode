class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        // use priority_queue (max heap)
        // pop k times, each time we make the value square then push back
        // pop all value
        priority_queue<int> pq;
        long long result = 0;
        for (auto const& gift : gifts) {
            pq.push(gift);
        }

        for (int i = 0; i < k; i++) {
            int top = pq.top();
            pq.pop();
            int square = sqrt(top);
            pq.push(square);
        }

        int pqSize = pq.size();
        for (int i = 0; i < pqSize; i++) {
            result += pq.top();
            pq.pop();
        }
        return result;
    }
};