class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }
        /*
        if (s.size() != goal.size()) {
            return false;
        }

        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s == goal) {
                return true;
            }
            s = s.back() + s;
            s.pop_back();
        }
        return false;
        */
        // abcdeabcde debac
        string newS = s + s;
        //return newS.find(goal) != string::npos;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            bool isValid = true;
            for (int j = 0; j < n; j++) {
                if (newS[i + j] != goal[j]) {
                    isValid = false;
                    break;
                }
            }
            if (isValid) {
                return true;
            }
        }
        return false;
    }
};