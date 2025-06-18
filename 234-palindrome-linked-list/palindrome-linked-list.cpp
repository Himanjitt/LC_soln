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

    ListNode* findMiddle(ListNode* head) {
        ListNode *fast = head, *slow = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* reverse(ListNode* head) {
        ListNode *curr = head, *prev = NULL, *fut = NULL;

        while (curr) {
            fut = curr->next;

            curr->next = prev;

            prev = curr;
            curr = fut;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;
        ListNode* middle = findMiddle(head);
        ListNode* revHead = reverse(middle);

        while (revHead) {
            if (head->val != revHead->val) {
                return false;
            }
            head = head->next;
            revHead = revHead->next;
        }

        return true;
    }
};