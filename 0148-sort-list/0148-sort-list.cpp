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
        // use vector <pair> to store the list
        // rearrange
        // TC: O(nlogn)
        // SC: O(n)
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        vector<pair<int, ListNode*>> nodeList;
        ListNode* prev = head;
        while (prev != nullptr) {
            nodeList.push_back({prev->val, prev});
            prev = prev->next;
        }

        // sort by val
        sort(nodeList.begin(), nodeList.end(), [](pair<int, ListNode*>& a, pair<int, ListNode*>& b) {
            return a.first < b.first;
        });

        // rearrange
        ListNode* dummy = new ListNode();
        head = dummy;
        for (int i = 0; i < nodeList.size(); i++) {
            head->next = nodeList[i].second;
            head = head->next;
        }
        head->next = nullptr;
        return dummy->next;
    }
};