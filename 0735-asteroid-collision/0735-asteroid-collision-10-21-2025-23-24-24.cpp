class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // only positive negative will collide
        // use stk
        // TC: O(n)
        // SC: O(n)
        stack<int> stk;
        for (auto const& asteroid : asteroids) {
            if (stk.empty()) {
                stk.push(asteroid);
            } else {
                bool isValid = true;
                while (!stk.empty() && stk.top() > 0 && asteroid < 0) {
                    if (stk.top() + asteroid > 0) {
                        isValid = false;
                        break;
                    } else if (stk.top() + asteroid == 0) {
                        isValid = false;
                        stk.pop();
                        break;
                    } else {
                        stk.pop();
                    } 
                }

                if (isValid) {
                    stk.push(asteroid);
                }
            }
        }

        vector<int> result;
        while (stk.size() > 0) {
            result.push_back(stk.top());
            stk.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};