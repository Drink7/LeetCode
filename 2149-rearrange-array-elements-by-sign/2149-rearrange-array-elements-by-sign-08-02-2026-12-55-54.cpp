class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
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
    }
};