class Solution {
public:
    int minSensors(int n, int m, int k) {
        // each sensor at most  k*k area
        // TC: O(m * n)
        // SC: O(1)
        int size = 2 * k + 1;
        int rows = (n + size - 1) / size;
        int cols = (m + size - 1) / size;

        return rows * cols;
    }
};