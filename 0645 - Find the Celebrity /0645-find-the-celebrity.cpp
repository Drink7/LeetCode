// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    /**
     * @param n a party with n people
     * @return the celebrity's label or -1
     */
    int findCelebrity(int n) {
        /*
        vector<bool> candidates(n, true);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (candidates[i] && i != j) {
                    if (knows(i, j) || !knows(j, i)) {
                        candidates[i] = false;
                    } else {
                        candidates[j] = false;
                    }
                }
            }
            if (candidates[i]) {
                return i;
            }
        }
        return -1;
        */
        // TC: O(n)
        // SC: O(1)
        int candidate = 0;

        // guest a candidates to be the celebrity
        for (int i = 1; i < n; i++) {
            if (knows(candidate, i)) {
                candidate = i;
            }
        }

        // Check our candidate is the celebrity or not
        for (int i = 0; i < n; i++) {
            if (i != candidate && (knows(candidate, i) || !knows(i, candidate))) {
                return -1;
            }
        }
        return candidate;
    }
};
