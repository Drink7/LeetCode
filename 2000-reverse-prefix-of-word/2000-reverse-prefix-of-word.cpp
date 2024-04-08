class Solution {
public:
    string reversePrefix(string word, char ch) {
        // find ch in word first
        // use two pointer to reverse
        // TC: O(n)
        // SC: O(1)
        int n = word.size();
        int chIndex = -1;
        for (int i = 0; i < n; i++) {
            if (word[i] == ch) {
                chIndex = i;
                break;
            }
        }
        if (chIndex != -1) {
            int left = 0;
            int right = chIndex;
            while (left < right) {
                swap(word[left], word[right]);
                left++;
                right--;
            }
        }
        return word;
    }
};