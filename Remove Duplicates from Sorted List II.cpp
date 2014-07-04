#include <stdlib.h>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head){
            return head;
        }
        ListNode n(0);
        ListNode *p = &n;
        ListNode *p2=head;
        while(p2){
            if(p2->next==nullptr||p2->next->val!=p2->val){
                p->next=p2;
                p=p->next;
                p2=p2->next;
                p->next=nullptr;
            }else{
                int value=p2->val;
                while(p2!=nullptr&&p2->val==value){
                    p2=p2->next;
                }
            }
        }
        return n.next;
    }
};