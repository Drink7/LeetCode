class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // Check h need to larger or equal to piles length
        // sort the piles, choose the speed bewteen the smallest piles size and the largest piles size
        // minimum speed -> as large as hour 
        // find the total hour which first equal to the h
        // TC: O(nlogn)
        // SC: O(1)
        sort(piles.begin(), piles.end());

        int left = 1;
        int right = piles.back();
        while (left <= right) {
            // mid is means the speed we choose
            int mid = left + (right - left) / 2;
            int spent = hourSpend(piles, mid);

            if (spent <= h) {
                if (mid == 1 || hourSpend(piles, mid - 1) > h) {
                    return mid;
                } else {
                    right = mid - 1;
                }
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }

    int hourSpend(vector<int>& piles, int speed) {
        int spent = 0;
        for (int pile : piles) {
            spent += ceil((double)pile / speed);
        }
        return spent;
    }
};