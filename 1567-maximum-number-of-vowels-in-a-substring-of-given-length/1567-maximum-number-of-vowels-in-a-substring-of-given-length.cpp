class Solution {
public:
    int maxVowels(string s, int k) {
        // substring with fixed window length k -> sliding window
        // TC: O(n)
        // SC: O(1)
        int n = s.size();
        int left = 0;
        int right = 0;
        int result = 0;
        int counter = 0;
        while (right < n) {
            if (isVowel(s[right])) {
                counter++;
            }

            if (right >= k - 1) {
                result = max(result, counter);

                // remove left char
                if (isVowel(s[left])) {
                    counter--;
                }
                left++;
            }
            right++;
        }
        return result;
    }

    bool isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;
        } else {
            return false;
        }
    }
};