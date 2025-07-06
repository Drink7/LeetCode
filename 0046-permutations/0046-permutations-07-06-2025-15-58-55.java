class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        if (nums == null || nums.length == 0) {
            return result;
        }
        dfs(result, new ArrayList<>(), nums, 0);
        return result;
    }

    private void dfs(List<List<Integer>> result, List<Integer> current, int[] nums, int count) {
        if (count == nums.length) {
            result.add(new ArrayList<>(current));
            return;
        }

        // used nums[i] = Integer.MIN_VALUE
        int numsLen = nums.length;
        for (int i = 0; i < numsLen; i++) {
            if (nums[i] == Integer.MIN_VALUE) {
                continue;
            }

            int curChoose = nums[i];
            current.add(curChoose);
            nums[i] = Integer.MIN_VALUE;
            dfs(result, current, nums, count + 1);
            current.remove(current.size() - 1);
            nums[i] = curChoose;
        }
    }
}