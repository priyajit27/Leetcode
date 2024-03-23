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
    ListNode* reverseList(ListNode* head) {
        ListNode *p,*q,*r;
        p=head;
        q=NULL;
        r=NULL;
        if(head==NULL)
            return NULL;
        while(p!=NULL){
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        head =q;
        return head;
    }
    void reorderList(ListNode* head) {
        ListNode* slow =head;
         ListNode* fast=head;
         while(fast && fast->next){
             slow=slow->next;
             fast=fast->next->next;
         }
         ListNode* head2=reverseList(slow->next);
           slow->next=NULL;
               ListNode* head1=head;
         while(head2){
               ListNode* temp1=head1->next;
                ListNode* temp2=head2->next;
                head1->next=head2;
                head2->next=temp1;
                head1=temp1;
                head2=temp2;
         }
    }
};