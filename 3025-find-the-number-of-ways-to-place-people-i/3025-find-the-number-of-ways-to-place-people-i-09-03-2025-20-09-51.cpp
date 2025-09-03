class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        // sort points with x
        // enumerate all upper-left and lower-right
        // current point is upper-left and next point lower-right
        // check there is no point x1 <= x <= x2 and y1 <= y <= y2
        // TC: O(n^3)
        // SC: O(1)
        int n = points.size();
        int cnt = 0;
        sort(points.begin(), points.end());
        for (int i = 0; i < n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                if (y1 >= y2) {
                    // cur -> upper-left
                    // next -> lower-right
                    bool isValid = true;
                    for (int k = i + 1; k < n; k++) {
                        int x = points[k][0];
                        int y = points[k][1];
                        if (k == j) {
                            continue;
                        }
                        if (x1 <= x && x <= x2 && y2 <= y && y <= y1) {
                            isValid = false;
                            break;
                        } 
                    }
                    if (isValid) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};