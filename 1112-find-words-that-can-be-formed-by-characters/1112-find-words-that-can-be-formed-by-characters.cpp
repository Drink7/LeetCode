class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        // create a 26 size vector array which count the letter number of chars
        // traverse all word in the words array
        // check the word is good or not by checking its letter existed in the letter number before
        // if it is good, count its string length
        // TC: O(m * n + k). m is the average size of the word in the words list
        // n is the words list size, k is chars string size
        // SC: O(1)
        vector<int> letterCnt(26, 0);
        int sum = 0;
        for (auto const& c : chars) {
            letterCnt[c - 'a']++;
        }

        for (auto const& word : words) {
            vector<int> copyCnt(letterCnt);
            bool isGood = true;
            for (auto const& c : word) {
                if (copyCnt[c - 'a'] == 0) {
                    isGood = false;
                    break;
                } else {
                    copyCnt[c - 'a']--;
                }
            }
            if (isGood) {
                sum += word.size();
            }
        }
        return sum;
    }
};