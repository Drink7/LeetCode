class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        // make {num, index} pair
        // sort by nums2
        // start to add nums1
        // if minHeap == k, calculate the score
        // if minHeap > k, pop the smallest nums1
        vector<pair<int, int>> numPairs;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long result = 0;
        long long sum = 0;
        int n = nums1.size();
        for (int i = 0; i < n; i++) {
            numPairs.push_back({nums2[i], nums1[i]});
        }

        sort(numPairs.rbegin(), numPairs.rend());

        for (auto const& p : numPairs) {
            minHeap.push(p.second); // nums1
            sum += p.second;
            if (minHeap.size() > k) {
                sum -= minHeap.top();
                minHeap.pop();
            }

            if (minHeap.size() == k) {
                // calculate scores
                long long tmp = sum * p.first;
                result = max(result, tmp);
            }
        }
        return result;
    }
};