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
//prev
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p=head;
        ListNode *prev=NULL;
        if(head==NULL||head->next==NULL)
        return head;
        else
        {
            prev=head;
            p=prev->next;
        }
        while(1)
        {
            if(prev->val==p->val)
            {
                if(p->next==NULL)
                {prev->next=NULL;break;}
                prev->next=p->next;}
            else
            {
                prev=p;
            if(p->next==NULL)
            break; }
            

            
            p=p->next;
        }
     return head;   
    }
};
