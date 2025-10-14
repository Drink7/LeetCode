class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        // if i + 2k - 1 >= n, start to check
        // i, i + 1...... i + k - 1
        // i + k - 1 +, i + k ..... i + 2*k - 1
        // true if find, false if either fail
        //i++
        // TC: O(n * k)
        // SC: O(1)
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i + 2 * k - 1 < n) {
                // valid
                bool isValid = true;
                // a
                for (int a = i + 1; a < i + k; a++) {
                    if (nums[a] <= nums[a - 1]) {
                        isValid = false;
                        break;
                    }
                }

                if (!isValid) continue;

                // b
                for (int b = i + k + 1; b < i + 2 * k; b++) {
                    if (nums[b] <= nums[b - 1]) {
                        isValid = false;
                        break;
                    }
                }

                if (isValid) {
                    return true;
                }
            }
        }
        return false;
    }
};