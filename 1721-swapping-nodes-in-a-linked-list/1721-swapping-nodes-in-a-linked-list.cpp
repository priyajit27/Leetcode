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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* curr=head;
        int count=0;
        while(curr){
            count++;
            curr=curr->next;
        }
        int n=count-k+1;
        int c=0;
         curr=head;
        ListNode* begin=NULL;
        ListNode* end=NULL;
        while(curr){
            c++;
            if(c==k)
                begin=curr;
            if(c==n)
                end=curr;
            if(begin!=NULL && end!=NULL)break;
            curr=curr->next;
        }
        swap(begin->val,end->val);
        return head;
    }
};