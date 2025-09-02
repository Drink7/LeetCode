class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // maxHeap with k size
        // priority_queue<int, int> <abs(x - arr[i]), arr[i]>
        // pop then sort again
        // TC: O(n + nlogk + klogk)
        // SC: O(k)
        priority_queue<pair<int, int>> maxHeap;
        for (auto const& num : arr) {
            int closet = abs(num - x);
            maxHeap.push({closet, num});
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        vector<int> result;
        while (maxHeap.size() > 0) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        sort(result.begin(), result.end());
        return result;
    }
};