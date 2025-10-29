class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        // use a left to store the lefty bottles
        // total += numBottles
        // sum = numBottles + left
        // numBottles = numBottles / numExchange
        // left = sum % numExchange
        // bottles = 15, change = 4
        // total = 15, numBottles = 3, left = 3
        // total = 18, numBottles = 1, left = 2
        // total = 19, numBottles = 0, left = 3
        int left = 0;
        int total = 0;
        while (numBottles) {
            total += numBottles;
            int sum = numBottles + left;
            numBottles = sum / numExchange;
            left = sum % numExchange;
        }
        return total;
    }
};