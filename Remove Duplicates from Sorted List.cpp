#include <stdlib.h>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head==nullptr) {
            return head;
        }
        ListNode *p = head;
        int pre = p->val;
        ListNode *p2=head;
        while(p->next!=nullptr){
            p=p->next;
            if(p->val!=pre){
                p2->next=p;
                p2=p2->next;
                pre=p->val;
            }
        }
        p2->next=nullptr;
        return head;
    }
};