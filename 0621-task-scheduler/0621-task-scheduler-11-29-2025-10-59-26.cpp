class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // each round will have n + 1
        // consume max freq first
        // calculate the task freq -> O(n)
        // put into heap -> nlogn
        // pop tasks and then store to vector -> O(n)
        // push back to heap O(n)
        // TC: O(nlogn)
        // SC: O(n)
        int freq[26] = {0};
        priority_queue<int> maxHeap;

        for (int i = 0; i < tasks.size(); i++) {
            freq[tasks[i] - 'A']++;
        }

        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) {
                maxHeap.push(freq[i]);
            }
        }

        // start schedule
        int roundSize = n + 1;
        int result = 0;
        while (maxHeap.size() > 0) {
            vector<int> arr; // store next round tasks
            int cnt = 0; // cnt task size
            // for each round
            for (int i = 0; i < roundSize; i++) {
                if (maxHeap.size() > 0) {
                    arr.push_back(maxHeap.top());
                    maxHeap.pop();
                    cnt++;
                }
            }

            // store it back to heap
            for (auto& num : arr) {
                num--;
                if (num > 0) {
                    maxHeap.push(num);
                }
            }

            if (maxHeap.size() > 0) {
                result += roundSize;
            } else {
                result += cnt;
            }
        }
        return result;
    }
};