class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // Brute Force, traverse gas station? -> TLE
        int totalGas = 0;
        int totalCost = 0;
        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
        }
        
        if (totalGas < totalCost) {
            return -1;
        }

        int start = 0;
        int curSum = 0;
        for (int i = 0; i < gas.size(); i++) {
            curSum += gas[i] - cost[i];

            if (curSum < 0) {
                curSum = 0;
                start = i + 1;
            }
        }
        return start;
    }
};