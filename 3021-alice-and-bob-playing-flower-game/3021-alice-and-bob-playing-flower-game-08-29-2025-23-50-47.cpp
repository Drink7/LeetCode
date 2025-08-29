class Solution {
public:
    long long flowerGame(int n, int m) {
        // alice first, and alice last
        // ABA -> Win
        // ABABA -> Win
        // ABAB -> Lose
        // sum must be an odd
        // one side must be odd, the other side must be even
        long long result = 0;
        // n side be odd
        result += (long long) ((n + 1) / 2) * (m / 2);

        // m side be odd
        result += (long long) (n / 2) * ((m + 1) / 2);
        return result;
    }
};