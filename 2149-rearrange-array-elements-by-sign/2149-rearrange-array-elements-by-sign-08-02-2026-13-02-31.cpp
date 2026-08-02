class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        /*
        // -1, -5, 2, 3
        // 2, -1, 3, -5
        // two vector array
        // then store in result
        // TC: O(n)
        // SC: O(n)
        vector<int> pos, neg, result;
        for (auto const& num : nums) {
            if (num >= 0) {
                pos.push_back(num);
            } else {
                neg.push_back(num);
            }
        }

        for (int i = 0; i < pos.size(); i++) {
            result.push_back(pos[i]);
            result.push_back(neg[i]);
        }
        return result;
        */
        
        // traverse and store the pos in index 0, 2, 4 ..., the neg in index 1, 3, 5
        // return ans
        int n = nums.size();
        int pos = 0, neg = 1;
        vector<int> result(n, 0);
        for (auto const& num : nums) {
            if (num >= 0) {
                result[pos] = num;
                pos += 2;
            } else {
                result[neg] = num;
                neg += 2;
            }
        }
        return result;
    }
};