class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        // append the code in the head and the tail
        // use fix size window k
        // TC: O(n)
        // SC: O(n)
        int n = code.size();
        vector<int> newCode(code.begin(), code.end());
        vector<int> result;
        newCode.insert(newCode.end(), code.begin(), code.end());

        if (k == 0) {
            for (int i = 0; i < n; i++) {
                result.push_back(0);
            }
        } else {
            int left = k > 0 ? 1 : n + k;
            int right = left;
            int sum = 0;
            int cnt = 0;
            while (cnt < n) {
                sum += newCode[right];
                if (right - left + 1 < abs(k)) {
                    right++;
                } else {
                    result.push_back(sum);
                    sum -= newCode[left];
                    left++;
                    right++;
                    cnt++;
                }
            }
        }
        return result;
    }
};