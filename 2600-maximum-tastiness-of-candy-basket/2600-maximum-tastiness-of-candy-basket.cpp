class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        // maximize the minimum value
        // aggressive cows
        // TC: O(nlogn + nlogm), n is price array length, m is price max value
        sort(price.begin(), price.end());
        int left = 0;
        int right = price.back() - price.front();
        while (left <= right) {
            int mid = left + (right - left) / 2;
            cout << "outer mid: " << mid << endl;
            if (checkTastiness(price, mid, k)) {
                cout << "inner mid: " << mid << endl;
                if (mid == price.size() - 1 || !checkTastiness(price, mid + 1, k)) {
                    return mid;
                } else {
                    left = mid + 1;
                }
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }

    bool checkTastiness(vector<int>& price, int val, int k) {
        int prev = price[0];
        int count = 1;
        for (int i = 1; i < price.size(); i++) {
            if (price[i] - prev >= val) {
                count++;
                prev = price[i];
            }
        }
        return count >= k;
    }
};