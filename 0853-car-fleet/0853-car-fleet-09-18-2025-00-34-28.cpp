class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // decreasing mono stack
        // TC: O(n)
        // SC: O(n)
        // check each position with target
        // calculate each car need how many time to target
        // mono stack, if fast car catch up, it would follow the fleet speed
        stack<float> stk;
        int n = position.size();
        vector<float> time(n, 0);
        for (int i = 0; i < n; i++) {
            time[i] = (float) (target - position[i]) / speed[i];
        }

        // from the end
        for (int i = n - 1; i >= 0; i--) {
            if (stk.empty()) {
                stk.push(time[i]);
            } else {
                if (time[i] > stk.top()) {
                    stk.push(time[i]);
                }
            }
        }
        return stk.size();
    }
};