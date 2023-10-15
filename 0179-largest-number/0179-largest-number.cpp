class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // tricky sort (s1 + s2) > (s2 + s1)
        // TC: O(nlogn)
        // SC: O(1)
        sort(nums.begin(), nums.end(), [](int& num1, int& num2){
            string s1 = to_string(num1);
            string s2 = to_string(num2);
            return s1 + s2 > s2 + s1;
        });

        // concat
        string result = "";
        for (int i = 0; i < nums.size(); i++) {
            if (nums[0] == 0) {
                return "0";
            }
            result += to_string(nums[i]);
        }
        return result;
    }
};