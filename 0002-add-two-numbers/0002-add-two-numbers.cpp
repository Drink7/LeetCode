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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // TC: O(m + n)
        // SC: O(n)
        // make final l1 is the sum of l1 + l2
        vector<ListNode*> nodeList;
        int carry = 0;
        while (l1 && l2) {
            int val = carry + l1->val + l2->val;
            ListNode* node = new ListNode(val % 10);
            nodeList.push_back(node);
            carry = val / 10;
            l1 = l1->next;
            l2 = l2->next;
        }

        // check l1 or l2
        while (l1) {
            int val = carry + l1->val;
            ListNode* node = new ListNode(val % 10);
            nodeList.push_back(node);
            l1->val = val % 10;
            carry = val / 10;
            l1 = l1->next;
        }

        while (l2) {
            int val = carry + l2->val;
            ListNode* node = new ListNode(val % 10);
            nodeList.push_back(node);
            l2->val = val % 10;
            carry = val / 10;
            l2 = l2->next;
        }
        
        // both l1 & l2 is nullptr, check carry
        if (carry != 0) {
            ListNode* node = new ListNode(carry);
            nodeList.push_back(node);
        }

        // link nodes
        for (int i = 0; i < nodeList.size(); i++) {
            if (i == nodeList.size() - 1) {
                nodeList[i]->next = nullptr;
            } else {
                nodeList[i]->next = nodeList[i + 1];
            }
        }
        return nodeList[0];
    }
};