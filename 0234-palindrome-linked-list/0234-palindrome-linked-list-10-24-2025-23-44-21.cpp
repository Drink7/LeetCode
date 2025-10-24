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
    bool isPalindrome(ListNode* head) {
        // store into a vector
        // check palindrome
        /*
        vector<int> arr;
        while (head) {
            arr.push_back(head->val);
            head = head->next;
        }

        int left = 0;
        int right = arr.size() - 1;
        while (left < right) {
            if (arr[left] != arr[right]) return false;
            left++;
            right--;
        }
        return true;
        */

        // use fast slow pointer to find mid point
        // if fast->next == nullptr, list is odd
        // left part need to go one steps for the start
        // TC: O(n)
        // SC: O(1)
        if (!head->next) return true;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* leftPart = nullptr;
        while (fast && fast->next) {
            fast = fast->next->next;
    
            // reverse the slow at the same time
            ListNode* next = slow->next;
            slow->next = leftPart;
            leftPart = slow;
            slow = next;
        }

        // if fast != nullptr, odd, leftPart go to leftPart->next
        if (fast) {
            slow = slow->next;
        }

        // start palindrome compare slow and leftPart
        while (slow && leftPart) {
            if (slow->val != leftPart->val) return false;
            slow = slow->next;
            leftPart = leftPart->next;
        }

        return true;
    }
};