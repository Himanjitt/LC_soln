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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* dummy = new ListNode(-1);
        ListNode* oddPointer = head;
        if(head->next == NULL){
            return head;
        }
        ListNode* evenPointer = head->next;
        ListNode* curr = dummy;
        while (oddPointer != NULL && oddPointer->next != NULL) {
            ListNode* temp = new ListNode(oddPointer->val);
            curr->next = temp;
            curr = curr->next;
            
            oddPointer = oddPointer->next->next;
            
        }
        if(oddPointer){
            ListNode* temp = new ListNode(oddPointer->val);
            curr->next = temp;
            curr = curr->next;
        }
        while (evenPointer != NULL && evenPointer->next != NULL) {
            ListNode* temp = new ListNode(evenPointer->val);
            curr->next = temp;
            curr = curr->next;
             
            evenPointer = evenPointer->next->next;
        }
        if(evenPointer){
            ListNode* temp = new ListNode(evenPointer->val);
            curr->next = temp;
            curr = curr->next;
        }

        return dummy->next;
    }
};