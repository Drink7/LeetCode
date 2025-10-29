/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // we're given the deleted node
        // and don't know its previous
        // copy next node val to this node
        // node0>next go to next next
        node->val = node->next->val;
        node->next = node->next->next;
    }
};