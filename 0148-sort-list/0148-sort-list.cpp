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
        // Use a vector to store
        // TC: O(nlogn)
        // SC: O(n)
        vector<pair<int, ListNode*>> nodeList;
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        while (head != nullptr) {
            nodeList.push_back({head->val, head});
            head = head->next;
        }

        // sort the vector
        sort(nodeList.begin(), nodeList.end(), [](pair<int, ListNode*> p1, pair<int, ListNode*> p2) {
            return p1.first < p2.first;
        });

        for (auto const& p : nodeList) {
            cur->next = p.second;
            cur = cur->next;
        }
        cur->next = nullptr;

        return dummy->next;
        */
        // divide and conquer way -> merge sort
        // we find the middle first
        // then reverse the middle to end and the head to middle part
        // TC: O(nlogn)
        // SC: O(1)
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* prev = nullptr;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }

        prev->next = nullptr;

        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);
        return mergeList(left, right);
    }

    ListNode* mergeList(ListNode* node1, ListNode* node2) {
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        while (node1 != nullptr && node2 != nullptr) {
            if (node1->val > node2->val) {
                cur->next = node2;
                node2 = node2->next;
            } else {
                cur->next = node1;
                node1 = node1->next;
            }
            cur = cur->next;
        }
        
        if (node1 != nullptr) {
            cur->next = node1;
        }

        if (node2 != nullptr) {
            cur->next = node2;
        }
        return dummy->next;
    }
};