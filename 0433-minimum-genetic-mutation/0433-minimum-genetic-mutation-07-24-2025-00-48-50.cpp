class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        // Same as 127
        // minimum number of mutations -> shortest path -> BFS
        // 1. check endGene in the bank
        // 2. BFS, use hash set for bank
        // 3. each step only change one character
        // TC: O(m * n^2), m is bank size, n is bank[i].size
        // SC: O(m)
        unordered_set<string> hashTable;
        bool isEndGeneExist = false;
        for (auto const& gene : bank) {
            if (gene == endGene) {
                isEndGeneExist = true;
            }
            hashTable.insert(gene);
        }

        if (!isEndGeneExist) {
            return -1; // no such a mutation
        }

        int number = 0;
        queue<string> q;
        q.push(startGene);
        while (q.size() > 0) {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                string cur = q.front();
                q.pop();

                if (cur == endGene) {
                    return number;
                }

                for (int i = 0; i < cur.size(); i++) {
                    char c = cur[i];

                    for (int j = 0; j < 4; j++) {
                        cur[i] = choice[j];
                        if (hashTable.count(cur) > 0) {
                            q.push(cur);
                            hashTable.erase(cur);
                        }
                        cur[i] = c;
                    }
                }
            }
            number++;
        }
        return -1; // fail to have a mutation

    }
private:
    char choice[4] = {'A', 'C', 'G', 'T'};
};