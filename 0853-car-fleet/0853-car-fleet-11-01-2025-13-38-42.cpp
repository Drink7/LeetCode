class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // calculate remain times (dist / speed)
        // stk, push stk
        // if top < incoming times, don't push
        stack<double> timeStk;
        vector<pair<int, int>> posSpd;
        int n = position.size();
        for (int i = 0; i < n; i++) {
            posSpd.push_back({position[i], speed[i]});
        }

        //sort(posSpd.rbegin(), posSpd.rend());
        /*
        sort(posSpd.begin(), posSpd.end(), [](auto &a, auto &b) {
            return a > b;
        });
        */
        sort(posSpd.begin(), posSpd.end(), greater());

        for (int i = 0; i < n; i++) {
            double time = (double) (target - posSpd[i].first) / posSpd[i].second;
            if (timeStk.empty() || timeStk.top() < time) {
                timeStk.push(time);
            }
        }
        return timeStk.size();
    }
};