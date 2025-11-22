class Solution {
public:
    Solution(vector<int>& w) {
        sumArr.resize(w.size(), 0);
        sumArr[0] = w[0];
        for (int i = 1; i < w.size(); i++) {
            sumArr[i] = w[i] + sumArr[i - 1];
        }
    }
    
    int pickIndex() {
        // use a sumArr to calculate prefixSum
        // use rand to pick rand() %  n + 1, find a num
        // binary search the prefixSum, find the first >= num, return the index
        // TC: O(logn)
        int num = 1 + rand() % sumArr.back();
        int left = 0, right = sumArr.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (sumArr[mid] < num) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
private:
    vector<int> sumArr;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */