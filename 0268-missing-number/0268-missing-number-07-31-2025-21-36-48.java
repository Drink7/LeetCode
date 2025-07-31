class Solution {
    public int missingNumber(int[] nums) {
        boolean[] checked = new boolean[nums.length + 1];
        int missedNum = -1;

        for(int i = 0; i < nums.length; i++) {
            checked[nums[i]] = true;
        }

        for (int i = 0; i < checked.length; i++) {
            if (!checked[i]) {
                missedNum = i;
                break;
            }
        }
        return missedNum;
    }
}