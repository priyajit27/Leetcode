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
ListNode* mergeList(ListNode* head1,ListNode* head2){
    ListNode* dummy=new ListNode(0);
     ListNode* temp=dummy;
    while(head1 && head2){
           if(head1->val<head2->val){
            temp->next=new ListNode(head1->val);
          head1=head1->next;
           }
           else{
                 temp->next=new ListNode(head2->val);
          head2=head2->next;
           }
           temp=temp->next;
    }
    while(head1){
          temp->next=new ListNode(head1->val);
          head1=head1->next;
          temp=temp->next;
    }
      while(head2){
          temp->next=new ListNode(head2->val);
          head2=head2->next;
          temp=temp->next;
    }
    return dummy->next;
}
    ListNode* sortList(ListNode* head) {
          if(head==NULL || head->next==NULL)
          return head;
          ListNode* temp=NULL;
           ListNode* slow=head;
            ListNode* fast=head;
          while(fast && fast->next){
             temp=slow;
             slow=slow->next;
             fast=fast->next->next;
          }
          temp->next=NULL;
          ListNode* l1=sortList(head);
           ListNode* l2=sortList(slow);
          return  mergeList(l1,l2);
           
    }
};