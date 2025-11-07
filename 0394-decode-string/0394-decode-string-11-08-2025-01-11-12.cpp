class Solution {
public:
    string decodeString(string s) {
        // count will store in count stack
        // string will store in str stack
        // curr record current string
        // num record current num
        // TC: O(n)
        // SC: O(n)
        stack<int> countStack;
        stack<string> stringStack;
        string curr = "";
        int num = 0;

        for (auto const& c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                countStack.push(num);
                stringStack.push(curr);
                num = 0;
                curr = "";
            } else if (c == ']') {
                string decodedString = stringStack.top();
                stringStack.pop();

                int repeat = countStack.top();
                countStack.pop();

                for (int i = 0; i < repeat; i++) {
                    decodedString += curr;
                }
                curr = decodedString;
            } else {
                curr += c;
            }
        }
        return curr;
    }
};