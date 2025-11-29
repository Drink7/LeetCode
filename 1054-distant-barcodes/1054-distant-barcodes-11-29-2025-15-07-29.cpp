class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        // same questions of Reorganize String
        // no two adjacent barcodes are equal
        // use maxHeap to store int, pop two maxHeap from the top and arrange
        // after arrange, push back to the heap if count > 0
        // TC: O(nlogn)
        // SC: O(n) 
        unordered_map<int, int> freqMap; // code, cnt
        priority_queue<pair<int, int>> maxHeap; // freq, code
        vector<int> result;
        for (auto const& code : barcodes) {
            freqMap[code]++;
        }

        for (auto const& [code, freq] : freqMap) {
            maxHeap.push({freq, code});
        }

        while (maxHeap.size() > 0) {
            if (maxHeap.size() > 1) {
                auto [topFreq, topCode] = maxHeap.top(); maxHeap.pop();
                auto [secFreq, secCode] = maxHeap.top(); maxHeap.pop();
                topFreq--;
                secFreq--;
                if (topFreq > 0) {
                    maxHeap.push({topFreq, topCode});
                }

                if (secFreq > 0) {
                    maxHeap.push({secFreq, secCode});
                }
                result.push_back(topCode);
                result.push_back(secCode);
            } else {
                result.push_back(maxHeap.top().second);
                maxHeap.pop();
            }
        }
        return result;
    }
};