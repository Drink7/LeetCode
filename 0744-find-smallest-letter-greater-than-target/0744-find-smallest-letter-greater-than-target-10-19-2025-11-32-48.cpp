class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int targetNum = target - 'a';
        int smallest = INT_MAX;
        char ans = '/0';
        
        for (int i = 0; i < letters.size(); i++) {
            int cNum = letters[i] - 'a';
            if (cNum > targetNum && cNum - targetNum < smallest) {
                smallest = cNum - targetNum;
                ans = letters[i];
            }
        }
        return smallest == INT_MAX ? letters[0] : ans;
    }
};