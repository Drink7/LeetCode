class Solution {
public:
    bool doesAliceWin(string s) {
        // if no vowels -> alice lose
        // else
        // even vowels -> odd + odd -> (A + B + A) -> alice win
        // odd vowles -> odd + even -> (A) -> alice win
        int cnt = 0;
        for (auto const& c : s) {
            if (isVowel(c)) {
                cnt++;
            }
        }

        if (cnt == 0) {
            return false;
        } else {
            return true;
        }
    }

    bool isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;
        }
        return false;
    }
};