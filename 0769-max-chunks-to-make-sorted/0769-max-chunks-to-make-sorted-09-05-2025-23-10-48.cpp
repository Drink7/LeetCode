class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        /*
        int cnt = 0;
        int maxVal = 0;
        for (int i = 0; i < arr.size(); i++) {
            maxVal = max(maxVal, arr[i]);
            if (maxVal == i) {
                cnt++;
            }
        }
        return cnt;
        */
        int minVal = arr.size() - 1;
        int cnt = 0;
        for (int i = arr.size() - 1; i >= 0; i--) {
            minVal = min(minVal, arr[i]);
            if (minVal == i) {
                cnt++;
            }
        }
        return cnt;
    }
};