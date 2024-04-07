class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        // two pointer of each word
        // TC: O(m * n), m is the words length, n is the average word length
        // SC: O(1)
        for (auto const& word : words) {
            int left = 0;
            int right = word.size() - 1;
            while (left <= right) {
                if (word[left] != word[right]) {
                    break;
                } else {
                    left++;
                    right--;
                }
            }
            if (left > right) {
                return word;
            }
        }
        return "";
    }
};