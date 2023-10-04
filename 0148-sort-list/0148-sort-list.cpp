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
    ListNode* sortList(ListNode* head) {
        // store all nodes
        // might have duplicate node value
        // TC: O(nlogn)
        // SC: O(n)
        map<int, vector<ListNode*>> nodeDict;
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        // store
        while (head != nullptr) {
            nodeDict[head->val].push_back(head);
            head = head->next;
        }

        // sort
        for (auto const& p : nodeDict) {
            for (auto const& node : p.second) {
                cur->next = node;
                cur = cur->next;
            }
        }
        cur->next = nullptr;
        cur = dummy->next;
        delete(dummy);
        return cur;
    }
};