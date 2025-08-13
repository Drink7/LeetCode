class Solution {
public:
    vector<int> partitionLabels(string s) {
        // Traverse the s and store the char count to hash table (map)
        // Traverse the s, delete count from map (and add to the partial total)
        // store to the set
        // If the set element is all zero count in the hash map
        // Reset the hash map with a new partial count until the end
        // TC: O(n^2)
        // SC: O(n)
        unordered_map<char, int> dict;
        for (auto const& c : s) {
            dict[c]++;
        }

        vector<int> result;
        unordered_set<char> partSet;
        int partCnt = 0;
        for (auto const& c : s) {
            partSet.insert(c);
            dict[c]--;
            partCnt++;

            // Check partial set is all zero, which means one part is finished
            bool isAllZero = true;
            for (auto const& letter : partSet) {
                if (dict[letter] != 0) {
                    isAllZero = false;
                    break;
                }
            }

            if (isAllZero) {
                partSet.clear();
                result.push_back(partCnt);
                partCnt = 0;
            }
        }
        return result;
    }
};