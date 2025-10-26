class Solution {
public:
    int totalMoney(int n) {
        // 1 2 3 4 5 6 7 -> 1 2 3 4 5 6 7 + 0 (Round 1)
        // 2 3 4 5 6 7 8 -> 1 2 3 4 5 6 7 + 7 (Round 2)
        // 3 4 5 6 7 8 9 -> 1 2 3 4 5 6 7 + 14 (Round 3)
        //......
        /*
        int round = n / 7;
        int day = n % 7;
        int total = 0;

        // calculate full round
        for (int i = 1; i <= round; i++) {
            int start = i;
            int end = i + 7;
            for (int i = start;i < end; i++) {
                total += i;
            }
            //total += (start + end) * 7 / 2;
        }

        // calculate day if remain
        if (day != 0) {
            int start = 1 + round;
            int end = start + day;
            for (int i = start; i < end; i++) {
                total += i;
            }
        }
        return total;
        */
        int monday = 1;
        int total = 0;
        while (n > 0) {
            for (int i = 0; i < min(n, 7); i++) {
                total += monday + i;
            }
            monday++;
            n -= 7;
        }
        return total;
    }
};