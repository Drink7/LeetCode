class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        // aaa, bbb, ccc are invalid
        // maxHeap to store <freq, char>
        
        // TC: O((a + b + c)log(a + b + c)
        // SC: O((a + b + c))
        priority_queue<pair<int, char>> maxHeap;
        // store in maxHeap
        if (a > 0) maxHeap.push({a, 'a'});
        if (b > 0) maxHeap.push({b, 'b'});
        if (c > 0) maxHeap.push({c, 'c'});

        string result = "";

        // start to concat
        while (maxHeap.size() > 0) {
            if (maxHeap.size() > 1) {
                auto [topFreq, topLetter] = maxHeap.top();
                maxHeap.pop();
                auto [secFreq, secLetter] = maxHeap.top();
                maxHeap.pop();

                if (result == "" || result.back() != topLetter) {
                    if (topFreq > 1) {
                        topFreq -= 2;
                        result = result + topLetter + topLetter;
                    } else {
                        topFreq -= 1;
                        result = result + topLetter;
                    }

                    if (secFreq > 0) {
                        secFreq -= 1;
                        result = result + secLetter;
                    }
                } else {
                    if (topFreq > 0) {
                        topFreq -= 1;
                        result = result + topLetter;
                    }

                    if (secFreq > 1) {
                        secFreq -= 2;
                        result = result + secLetter + secLetter;
                    } else {
                        secFreq -= 1;
                        result = result + secLetter;
                    }
                }

                if (topFreq > 0) {
                    maxHeap.push({topFreq, topLetter});
                }

                if (secFreq > 0) {
                    maxHeap.push({secFreq, secLetter});
                }
            } else {
                auto [topFreq, topLetter] = maxHeap.top();
                maxHeap.pop();
                if (result == "" || result.back() != topLetter) {
                    if (topFreq > 1) {
                        topFreq -= 2;
                        result = result + topLetter + topLetter;
                    } else {
                        topFreq -= 1;
                        result = result + topLetter;
                    }
                } else {
                    if (topFreq > 0) {
                        topFreq -= 1;
                        result = result + topLetter;
                    }
                }
            }
        }
        return result;
    }
};