class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // sort
        // find the first value that piles / speed >= h
        // TC: O(nlogn)
        // SC: O(1)
        int n = piles.size();
        sort(piles.begin(), piles.end());
        int low = 1;
        int high = piles[n - 1];
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int time = eatTime(piles, mid);
            if (time <= h) {
                if (mid == 1 || eatTime(piles, mid - 1) > h) {
                    return mid;
                } else {
                    high = mid - 1;
                }
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }

    int eatTime(vector<int>& piles, int speed) {
        int time = 0;
        for (auto const& pile : piles) {
            time += (pile + speed - 1) / speed;
        }
        return time;
    }
};