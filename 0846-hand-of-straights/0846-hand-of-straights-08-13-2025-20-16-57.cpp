class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // hand.size() % groupSize  > 0 -> false;
        // store in hash map
        // sort
        // greedy to take each group with group size
        // TC: O(nlogn)
        // SC: O(n)
        if (hand.size() % groupSize != 0) {
            return false;
        }
        unordered_map<int, int> handMap;
        for (auto const& num : hand) {
            handMap[num]++;
        }

        sort(hand.begin(), hand.end());

        for (auto const& num : hand) {
            if (handMap[num] == 0) {
                continue;
            }
            
            for (int i = num; i < num + groupSize; i++) {
                if (handMap[i] == 0) {
                    return false;
                }
                handMap[i]--;
            }
        }
        return true;
    }
};