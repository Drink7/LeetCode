class Solution {
public:
    Solution(vector<int>& w) {
        // Find first larger or equal to
        // TC: O(logn + n)
        // SC: O(n)
        prefixSum.assign(w.begin(), w.end());
        for (int i = 1; i < w.size(); i++) {
            prefixSum[i] += prefixSum[i - 1];
        }
        srand(0);
    }
    
    int pickIndex() {
        int randNum = 1 + rand() % (prefixSum.back() - 1 + 1);
        int left = 0;
        int right = prefixSum.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midVal = prefixSum[mid];
            if (midVal >= randNum) {
                if (mid == 0 || prefixSum[mid - 1] < randNum) {
                    return mid;
                } else {
                    right = mid - 1;
                }
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
private:
    vector<int> prefixSum;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */