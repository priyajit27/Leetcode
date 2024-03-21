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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* head=list1;
         ListNode* head1=head;
        for(int i=0;i<a-1;i++){
            list1=list1->next;
        }
        
          for(int i=0;i<b;i++){
            head1=head1->next;
        }
        head1=head1->next;
        cout<<head1->val;
        
        list1->next=list2;
        
        while(list2->next!=NULL){
            list1=list2;
           list1=list1->next;
            list2=list2->next;
        }
        cout<<list1->val;
        list1->next=head1;
        
        // list1=head1;
        return head;
    }
};