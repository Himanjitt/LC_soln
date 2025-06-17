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
        ListNode *curr1 = l1, *curr2 = l2;
        ListNode* head = new ListNode(0);
        ListNode* tail = head;
        int carry = 0;
        while (curr1 || curr2) {
            int sum = 0;
            if (curr1) {
                sum += curr1->val;
                curr1 = curr1->next;
            }
            if (curr2) {
                sum += curr2->val;
                curr2 = curr2->next;
            }
            sum += carry;
            ListNode* temp = new ListNode(sum % 10);
            tail->next = temp;
            tail = tail->next;
            carry = sum / 10;
        }

        if (carry) {
            ListNode* temp = new ListNode(carry);
            tail->next = temp;
        }

        head = head->next;
        return head;
    }
};