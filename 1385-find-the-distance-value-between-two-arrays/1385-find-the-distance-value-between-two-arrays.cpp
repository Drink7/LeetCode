class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        /*
        // Brute Force
        // TC: O(n^2)
        // SC: O(1)
        int result = 0;
        for (auto const& u : arr1) {
            bool isValid = true;
            for (auto const& v : arr2) {
                if (abs(u - v) <= d) {
                    isValid = false;
                    break;
                }
            }
            if (isValid) {
                result++;
            }
        }
        return result;
        */

        // Binary Search
        // TC: O(nlogn)
        // SC: O(1)
        int result = 0;
        sort(arr2.begin(), arr2.end());
        for (auto const& u : arr1) {
            bool isValid = true;

            int low = 0;
            int high = arr2.size() - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (abs(u - arr2[mid]) <= d) {
                    isValid = false;
                    break;
                }

                // need to check u & arr2[mid] which is larger
                // u > arr2[mid] or arr2[mid] > u
                if (arr2[mid] > u) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            if (isValid) {
                result++;
            }
        }
        return result;
    }
};