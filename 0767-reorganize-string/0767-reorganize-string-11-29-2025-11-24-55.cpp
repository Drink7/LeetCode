class Solution {
public:
    string reorganizeString(string s) {
        // maxHeap store freq
        // pop out two freq and construct
        // check the last cycle, if the last top element count > 1, must be invalid
        // aaab
        // ab --> aa
        // else the string is valid
        // TC: O(nlogn)
        // SC: O(n)
        unordered_map<char, int> freqMap;
        priority_queue<pair<int, char>> maxHeap; // cnt, char
        string result = "";

        for (auto const& c : s) {
            freqMap[c]++;
        }

        // store back tomaxHeap
        for (auto const& [letter, count] : freqMap) {
            maxHeap.push({count, letter});
        }

        while (maxHeap.size() > 0) {
            if (maxHeap.size() > 1) {
                auto [topCount, topLetter] = maxHeap.top();
                maxHeap.pop();
                result += topLetter;
                auto [secCount, secLetter] = maxHeap.top();
                maxHeap.pop(); 
                result += secLetter;

                topCount--;
                secCount--;
                if (topCount > 0) {
                    maxHeap.push({topCount, topLetter});
                }

                if (secCount > 0) {
                    maxHeap.push({secCount, secLetter});
                }
            } else {
                auto [topCount, topLetter] = maxHeap.top();
                maxHeap.pop(); 
                if (topCount > 1) {
                    return ""; // invalid
                } else {
                    result += topLetter;
                }
            }
        }
        return result;
    }
};