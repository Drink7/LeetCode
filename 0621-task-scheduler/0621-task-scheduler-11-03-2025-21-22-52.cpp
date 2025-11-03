class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // maxheap with freq, char, we can only store int here
        // when pop out, cnt, and store to a vector
        // if the vector length > 0, result += n
        // if the vector length == 0, just result += cnt
        // TC: O(n)
        // SC: O(n)
        unordered_map<char, int> dict;
        priority_queue<int> maxHeap;
        for (auto const& c : tasks) {
            dict[c]++;
        }

        for (auto const& p : dict) {
            maxHeap.push(p.second);
        }

        // start to count
        int result = 0;
        int groupSize= n + 1;
        while (maxHeap.size() > 0) {
            int time = 0;
            vector<int> tmp;

            for (int i = 0; i < groupSize; i++) {
                if (maxHeap.size() > 0) {
                    // greedy fetch the max
                    int top = maxHeap.top(); maxHeap.pop();
                    tmp.push_back(top);
                    time++;
                }
            }

            // push back to maxHeap
            for (auto& num : tmp) {
                num--;
                if (num > 0) {
                    maxHeap.push(num);
                }
            }

            if (maxHeap.size() > 0) {
                result += groupSize;
            } else {
                result += time;
            }
        }
        return result;
    }
};