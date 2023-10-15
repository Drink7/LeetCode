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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        /*
        // Brute Force
        // Store Node in a set
        // TC: O(m + n)
        // SC: O(m)
        unordered_set<ListNode*> listSet;
        while (headA != nullptr) {
            listSet.insert(headA);
            headA = headA->next;
        }

        // check intersect
        while (headB != nullptr) {
            if (listSet.count(headB)) {
                return headB;
            }
            headB = headB->next;
        }
        return nullptr;
        */

        ListNode* node1 = headA;
        ListNode* node2 = headB;
        while (node1 != node2) {
            if (node1 == nullptr) {
                node1 = headB;
            } else {
                node1 = node1->next;
            }

            if (node2 == nullptr) {
                node2 = headA;
            } else {
                node2 = node2->next;
            }
        }
        return node1;
    }
};