class Solution {
public:
    string sortVowels(string s) {
        // use a minHeap to get the largest ASCII vowels value
        // TC: O(nlogn)
        // SC: O(n)
        priority_queue<char, vector<char>, greater<char>> minHeap;
        for (auto const& c : s) {
            if (isVowels(c)) {
                minHeap.push(c);
            }
        }

        string result = "";
        // replace (sort)
        for (auto const& c : s) {
            if (isVowels(c)) {
                result += minHeap.top();
                minHeap.pop();
            } else {
                result += c;
            }
        }
        return result;
    }

    bool isVowels(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;
        }

        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            return true;
        }

        return false;
    }
};