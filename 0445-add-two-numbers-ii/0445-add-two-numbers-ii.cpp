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
      ListNode* reverse(ListNode* head) {
       if(head==NULL || head->next ==NULL)
           return head;
        ListNode* newnode=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return newnode;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        l1=reverse(l1);
        l2=reverse(l2);
           if(l1==NULL && l2==NULL)
          return NULL;
        ListNode* l3=new ListNode(0);
         ListNode* head=l3;
         int carry=0;
        while(l1!=NULL && l2!=NULL){
                int x=(l1->val+l2->val+carry);
                carry=x/10;
                l3->next=new ListNode(x%10);
                  l3=l3->next;
                l1=l1->next;
                 l2=l2->next;
        }

    while(l1 ){
          int x=(l1->val+carry);
                carry=x/10;
                l3->next=new ListNode(x%10);
                  l3=l3->next;
                l1=l1->next;
                //  l2=l2->next;
    }
     while(l2 ){
                int x=(l2->val+carry);
                carry=x/10;
                l3->next=new ListNode(x%10);
                  l3=l3->next;
                // l1=l1->next;
                 l2=l2->next;
    }
    if(carry==1)
     l3->next=new ListNode(1);
     ListNode* ans=reverse(head->next);
        return ans;
    }
};