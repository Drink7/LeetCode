class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        // math
        // until no any numBottles (numBottles = 0)
        // TC: O(log(numExchange))
        // SC: O(1)
        int exchange = numExchange;
        int drink = numBottles;
        int empty = 0;
        int sum = 0;
        while (drink > 0) {
            sum += drink;
            empty += drink;
            drink = 0;
            while (empty >= numExchange) {
                empty -= numExchange;
                drink++;
                numExchange++;
            }
        }
        return sum;
    }
};