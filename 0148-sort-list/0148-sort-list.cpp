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
        /*
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
        */
        // merge sort
        // TC:O(nlogn)
        // SC: O(1)
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* prev = nullptr;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }

        prev->next = nullptr;

        // do left and right part merge sort
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);
        return mergeTwoList(left, right);
    }

    ListNode* mergeTwoList(ListNode* nodeA, ListNode* nodeB) {
        if (nodeA == nullptr) {
            return nodeB;
        }

        if (nodeB == nullptr) {
            return nodeA;
        }

        if (nodeA->val > nodeB->val) {
            nodeB->next = mergeTwoList(nodeA, nodeB->next);
            return nodeB;
        } else {
            nodeA->next = mergeTwoList(nodeA->next, nodeB);
            return nodeA;
        }
    }
};