class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        // split from the end
        // find the value index, if the traverse process doesn't find the minimum, that must be a chunk
        // then start the next chunk from the minimum index - 1
        // TC: O(n)
        // SC: O(1)
        int index = arr.size() - 1;
        int cnt = 0;
        while (index >= 0) {
            int minValue = arr[index];
            for (int i = index; i >= minValue; i--) {
                if (arr[i] < minValue) {
                    minValue = arr[i];
                }
            }
            if (minValue >= 0) {
                cnt++;
                index = minValue - 1;
            }
        }
        return cnt;
    }
};