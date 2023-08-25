class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // mod 10 to and sort
        // if the moded numbr is the same, put the fewer digit first
        // if digit the same, compare the value
        // TC: O(nlogn)
        // SC: O(1)
        string result;

        sort(nums.begin(), nums.end(), [](int a, int b) {
           string strA = to_string(a);
           string strB = to_string(b);
           return strA + strB > strB + strA;
        });

        // if nums is all zero, return directly
        if (nums[0] == 0) {
            return "0";
        }
    
        // then append all these value
        for (int i = 0; i < nums.size(); i++) {
            result += to_string(nums[i]);
        }

        return result;
    }
};