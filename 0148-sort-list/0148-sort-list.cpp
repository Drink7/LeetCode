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
        // Use vector + pair store (val, ListNode), then sort 
        // return dummy.next
        // TC: O(n + nlogn + n) -> O(nlogn)
        // SC: O(n)
        vector<pair<int, ListNode*>> nodeList;
        while (head != nullptr) {
            nodeList.push_back({head->val, head});
            head = head->next;
        }
        sort(nodeList.begin(), nodeList.end(), [](pair<int, ListNode*> a, pair<int, ListNode*> b) {
            return a.first < b.first;
        });

        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        for (auto const& p : nodeList) {
            cur->next = p.second;
            cur = cur->next;
        }
        cur->next = nullptr;
        return dummy->next;
    }
};