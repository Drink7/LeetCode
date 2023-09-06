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
    }
};