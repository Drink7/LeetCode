class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // find nums not index
        // must not contain duplicate
        // sort with two pointer
        int n = nums.size();
        sort(nums.begin(), nums.end());

        // -4, -1, -1, 0, 1, 2
        // i...........i
        //      left         right
        //.    i.   left.    right --> (-1, -1, 2) (-1, 0, 1)
        // 
        vector<vector<int>> result;
        for (int i = 0; i < n - 2; i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                int left = i + 1;
                int right = n - 1;
                while (left < right) {
                    if (nums[i] + nums[left] + nums[right] == 0) {
                        result.push_back({nums[i], nums[left], nums[right]});

                        // remove duplicate
                        left++;
                        right--;

                        while (left < right && nums[left] == nums[left - 1]) {
                            left++;
                        }

                        while (left < right && nums[right] == nums[right + 1]) {
                            right--;
                        }
                    } else if (nums[i] + nums[left] + nums[right] > 0) {
                        right--;
                    } else {
                        left++;
                    }
                }
            }
        }

        return result;
    }
};