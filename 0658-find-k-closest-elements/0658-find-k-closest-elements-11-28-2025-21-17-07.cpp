class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        /*
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
        */
        // sorted array
        // sliding window
        // find window difference is minimum
        // TC; O(n)
        // SC: O(1)
        int left = 0, right = 0;
        int ans = 0;
        int windowDifSum = 0;
        int windowMin = INT_MAX;
        int n = arr.size();
        vector<int> result;
        while (right < n) {
            windowDifSum += abs(arr[right] - x);
            if (right - left + 1 == k) {
                if (windowDifSum < windowMin) {
                    windowMin = windowDifSum;
                    ans = left;
                }
                // move left
                windowDifSum -= abs(arr[left] - x);
                left++;
            }
            // move right
            right++;
        }

        for (int i = ans; i < ans + k; i++) {
            result.push_back(arr[i]);
        }
        return result;
    }
};