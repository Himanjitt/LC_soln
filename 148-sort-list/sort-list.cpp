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
    ListNode* findMiddle(ListNode*& head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode*& left, ListNode*& right) {
        
        ListNode* dummy = new ListNode(-1);
        ListNode* dummyHead = dummy;

        while (left != NULL && right != NULL) {
            if (left->val <= right->val) {
                dummy->next = left;
                dummy = dummy->next;
                left = left->next;
            } else {
                dummy->next = right;
                dummy = dummy->next;
                right = right->next;
            }
        }

        //if left remains
        while (left != NULL) {
            dummy->next = left;
            dummy = dummy->next;
            left = left->next;
        }

        while (right != NULL) {
            dummy->next = right;
            dummy = dummy->next;
            right = right->next;
        }
        return dummyHead->next;
    }

    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // break into two halves
        ListNode* mid = findMiddle(head);
        ListNode* right = mid->next;
        mid->next = NULL;
        ListNode* left = head;

        // Sort
        left = sortList(left);
        right = sortList(right);

        ListNode* mergeLL = merge(left, right);
        return mergeLL;
    }
};