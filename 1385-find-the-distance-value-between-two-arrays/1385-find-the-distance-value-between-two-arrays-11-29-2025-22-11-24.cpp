class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        // sort arr1, arr2
        // traverse arr1, find |arr1[i] - arr2[mid]|
        // find the last <= d
        // TC: O(mlogm + nlogn)
        // SC: O(1)
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        int cnt = 0;
        for (auto const& num : arr1) {
            bool isValid = true;
            int left = 0;
            int right = arr2.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (abs(num - arr2[mid]) <= d) {
                    isValid = false;
                    break;
                }

                if (arr2[mid] > num) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            if (isValid) {
                cnt++;
            }
        }
        return cnt;
        /*
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        int cnt = 0;
        for (auto const& num1 : arr1) {
            bool isValid = true;
            for (auto const& num2 : arr2) {
                if (abs(num1 - num2) <= d) {
                    isValid = false;
                    break;
                }
            }
            if (isValid) {
                cnt++;
            }
        }
        return cnt;
        */

    }
};