class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        // remainA
        // remainB
        // if (remainA < plants[left]) cnt++; remainA = capacityA - plants[left]
        // else remainA -= plants[left]
        // if (remainB < plants[right]) cnt++; remainB = capacityB - plants[right]
        // else remainB -= plants[right]
        // TC: O(n)
        // SC: O(1)
        int remainA = capacityA;
        int remainB = capacityB;
        int left = 0, right = plants.size() - 1;
        int cnt = 0;
        while (left < right) {
            if (remainA < plants[left]) {
                cnt++;
                remainA = capacityA - plants[left];
            } else {
                remainA -= plants[left];
            }

            if (remainB < plants[right]) {
                cnt++;
                remainB = capacityB - plants[right];
            } else {
                remainB -= plants[right];
            }
            left++;
            right--;
        }
        if (plants.size() % 2 == 1) {
            // In case both Alice and Bob reach the same plant, 
            // the one with more water currently in his/her watering can should water this plant.
            // If they have the same amount of water, then Alice should water this plant.
            if (remainB < plants[right] && remainA < plants[right]) {
                cnt++;
            }
        }
        return cnt;
    }
};