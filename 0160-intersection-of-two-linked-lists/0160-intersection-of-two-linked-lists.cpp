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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n=0;int m=0;
        ListNode* ptr1=headA;
        ListNode* ptr2=headB;
        
        while(ptr1!=NULL){
            n++;
            ptr1=ptr1->next;
        }
           while(ptr2!=NULL){
            m++;
            ptr2=ptr2->next;
        }
        
        int a=abs(n-m);
        ptr1=headA;
        ptr2=headB;
        
        while(a--){
            if(n>m)
                ptr1=ptr1->next;
             else
                ptr2=ptr2->next;
        }
        while(ptr1!=ptr2){
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        return ptr2;
    }
};