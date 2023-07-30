class Solution {
public:
    string reverseVowels(string s) {
        // TC: O(n)
        // SC: O(1)
        int right = s.size() - 1;
        int left = 0;
        string result = s;

        while (left <= right) {
            if (dict.count(result[left]) && dict.count(result[right])) {
                swap(result[left], result[right]);
                left++;
                right--;
            } else {
                if (!dict.count(result[left])) {
                    left++;
                }

                if (!dict.count(result[right])) {
                    right--;
                }
            }
        }
        return result;
    }
private:
    unordered_set<char> dict = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
};