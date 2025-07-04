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
    vector<ListNode*> reverseList(ListNode* head) {
        ListNode *prev = NULL, *curr, *fut = NULL;

        curr = head;
        while (curr != NULL) { // save the future node
            fut = curr->next;
            // reverse curr node
            curr->next = prev;
            // increment the pointer;
            prev = curr;
            curr = fut;
        }

        ListNode* newhead=prev;
        return {newhead, head};
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == NULL) return NULL;
        if (left == right) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* leftend = dummy;
        for (int i = 1; i <= left - 1; i++) {
            leftend = leftend->next;
        }

        ListNode* rightend = head;
        for (int i = 1; i < right; i++) {
            rightend = rightend->next;
        }

        ListNode* post = rightend->next;
        rightend->next = NULL;

        vector<ListNode*> ends = reverseList(leftend->next);

        leftend->next = ends[0];
        ends[1]->next = post;

        return dummy->next;

    }
};

/*
      h
(0)-> 1 ->2->3->4->5
          L     R   
*/