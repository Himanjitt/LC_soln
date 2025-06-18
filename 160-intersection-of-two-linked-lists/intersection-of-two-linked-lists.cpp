/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int sizeA = 0, sizeB = 0;
        ListNode *currA = headA, *currB = headB;

        while (currA) {
            sizeA++;
            currA = currA->next;
        }
        while (currB) {
            sizeB++;
            currB = currB->next;
        }
        // take them to the same starting point
        currA = headA, currB = headB;
        while (sizeA != sizeB) {
            if (sizeA > sizeB) {
                currA = currA->next;
                sizeA--;
            } else {
                currB = currB->next;
                sizeB--;
            }
        }

        while(currA != currB){
            currA=currA->next;
            currB=currB->next;
        }

        return currA; //or currB
    }
};