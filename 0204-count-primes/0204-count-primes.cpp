class Solution {
public:
    int countPrimes(int n) {
        // sieve of Eratosthenes
        // TC: O(n log log n)
        // SC: O(n)
        vector<bool> primes(n, true);
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (primes[i]) {
                count++;
                for (int j = 2; j * i < n; j++) {
                    primes[i * j] = false;
                }
            }
        }
        return count;
    }
};