class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        // % 3 == 0 -> all sum
        // % 3 == 1 -> two's 2 or one 1
        // % 3 == 2 -> one 2 or two's 1
        int sum = 0;
        vector<int> mod1;
        vector<int> mod2;
        for (auto const& num : nums) {
            if (num % 3 == 1) {
                mod1.push_back(num);
            } else if (num % 3 == 2) {
                mod2.push_back(num);
            }
            sum += num;
        }

        sort(mod1.begin(), mod1.end());
        sort(mod2.begin(), mod2.end());

        if (sum % 3 == 1) {
            // fetch two 2 or one 1
            int two2 = INT_MAX;
            int one1 = INT_MAX;
            if (mod2.size() >= 2) {
                two2 = mod2[0] + mod2[1];
            }

            if (mod1.size() >= 1) {
                one1 = mod1[0];
            }

            int minNum = min(two2, one1);
            if (minNum == INT_MAX) {
                return 0;
            } else {
                sum -= minNum;
            }
        } else if (sum % 3 == 2) {
            // fetch one 2 or two 1
            int one2 = INT_MAX;
            int two1 = INT_MAX;
            if (mod2.size() >= 1) {
                one2 = mod2[0];
            }

            if (mod1.size() >= 2) {
                two1 = mod1[0] + mod1[1];
            }

            int minNum = min(one2, two1);
            if (minNum == INT_MAX) {
                return 0;
            } else {
                sum -= minNum;
            }
        }
        return sum;
    }
};