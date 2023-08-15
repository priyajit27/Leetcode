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
    ListNode* partition(ListNode* head, int x) {
        ListNode* head1=NULL;
          ListNode* head2=NULL;
        ListNode* head3=NULL;
        ListNode* head4=NULL;
        while(head){
            if(head->val<x){
               if(head1==NULL){
                   head1=head;
                   head3=head;
               }
                else{
                    head1->next=head;
                    head1=head1->next;
                }
            }
            else{
                 if(head2==NULL){
                   head2=head;
                   head4=head;
               }
                else{
                    head2->next=head;
                    head2=head2->next;
                }
            }
            head=head->next;
        }
        //  while(head){
        //     if(head->val>=x){
        //        if(head2==NULL){
        //            head2=head;
        //            head4=head;
        //        }
        //         else{
        //             head2->next=head;
        //             head2=head2->next;
        //         }
        //     }
        //     head=head->next;
        // }
      if(head4)
          head2->next=NULL;
        if(head3)
            head1->next=head4;
            else return head4;
        return head3;
    }
};