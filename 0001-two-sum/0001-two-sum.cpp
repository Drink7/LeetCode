class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*
        // Hash table (unorder_map)
        // TC: O(n)
        // SC: O(n)
        // store val, id
        unordered_map<int, int> dict;
        for (int i = 0; i < nums.size(); i++) {
            int remain = target - nums[i];
            if (dict.count(remain)) {
                return {dict[remain], i};
            } else {
                dict[nums[i]] = i;
            }
        } 
        return {-1, -1};
        */
        // Two pointer with sorted
        // TC: O(nlogn)
        // SC: O(n)
        vector<pair<int, int>> numsArr;
        for (int i = 0; i < nums.size(); i++) {
            numsArr.push_back({nums[i], i});
        }

        sort(numsArr.begin(), numsArr.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.first < b.first;
        });

        int left = 0;
        int right = numsArr.size() - 1;
        while (left < right) {
            int sum = numsArr[left].first + numsArr[right].first;
            if (sum == target) {
                return {numsArr[left].second, numsArr[right].second};
            } else if (sum > target) {
                right--;
            } else {
                left++;
            }
        }
        return {};
    }
};