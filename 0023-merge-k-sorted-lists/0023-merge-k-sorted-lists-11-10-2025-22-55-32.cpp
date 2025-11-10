/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // minHeap
        // nlog k
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap(cmp);

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                minHeap.push({lists[i]});
            }
        }

        ListNode dummy(0);
        ListNode* cur = &dummy;
        // start merge
        while (minHeap.size() > 0) {
            ListNode* smallNode = minHeap.top();
            minHeap.pop();
            cur->next = smallNode;
            if (smallNode->next) {
                minHeap.push(smallNode->next);
            }
            cur = cur->next;
        }
        return dummy.next;
    }
};