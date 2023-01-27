
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        int nodes = 0;
        for(ListNode *h = head; h != nullptr; h = h->next) nodes++;

        int rotate = k % nodes;

        if(rotate == 0) return head;

        ListNode *l1 = nullptr, *prev = nullptr, *curr = head;
        ListNode *p = nullptr;

        while(curr) {
            prev = l1;
            l1 = l1 == nullptr ? l1 : l1 -> next;
            if(--rotate == 0) l1 = head;
            p = curr;
            curr = curr -> next;
        }

        prev -> next = nullptr;
        p -> next = head;
        return l1;
    }
};
