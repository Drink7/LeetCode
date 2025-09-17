class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // monotonic stack
        // TC: O(n)
        // SC: O(n)
        vector<pair<int, int>> dict;
        int n = position.size();
        stack<float> fleetStack;
        for (int i = 0; i < n; i++) {
            dict.push_back({position[i], speed[i]});
        }

        sort(dict.begin(), dict.end());

        for (int i = n - 1; i >= 0; i--) {
            float timeTaken = (float)(target - dict[i].first) / dict[i].second;
            if (fleetStack.empty() || timeTaken > fleetStack.top()) {
                fleetStack.push(timeTaken);
            }
        }
        return fleetStack.size();
    }
};