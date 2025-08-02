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
/*
Steps
1) Reverse the LL from the middle 
2) Join the start to the end iteratively
*/

    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* fut = NULL;

        while(curr){
            fut = curr->next;
            curr->next = prev;

            prev = curr;
            curr = fut;
        }

        return prev;
    }


    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return;

        ListNode* middle = findMiddle(head);

        ListNode* revHead = reverse(middle);
        
        ListNode* curr = head;
        ListNode* rev = revHead;

        while(rev->next != NULL){
            ListNode* tempCurr = curr->next;
            curr->next = rev;

            ListNode* tempRev = rev->next;
            rev->next = tempCurr;

            curr = tempCurr;
            rev = tempRev;
        }

    }
};