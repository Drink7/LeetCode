class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        // math
        // until no any numBottles (numBottles = 0)
        // TC: O(log(numExchange))
        // SC: O(1)
        int drink = numBottles;
        int empty = 0;
        int sum = 0;
        while (drink > 0) {
            int roundTotal = drink + empty;
            sum += drink;
            empty = roundTotal % numExchange;
            drink = roundTotal / numExchange;
        }
        return sum;
    }
};