
#include <stdlib.h>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if(head==nullptr||head->next==nullptr||k==0){
            return head;
        }
        int len=1;
        ListNode *p=head;
        while(p->next!=nullptr){
            p=p->next;
            len++;
        }
        k=k%len;
        ListNode *p2=head;
        p=head;
        for(int i=0;i<k;i++){
            p=p->next;
        }
        while(p->next!=nullptr){
            p=p->next;
            p2=p2->next;
        }
        p->next=head;
        ListNode *newHead = p2->next;
        p2->next=nullptr;
        return newHead;
    }
};