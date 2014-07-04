
#include <stdlib.h>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *front=head, *back=head, *pre(0);
        for(int i=0;i<n;i++){
            front=front->next;
        }
        while(front!=nullptr){
            pre=back;
            front=front->next;
            back=back->next;
        }
        if(pre==nullptr){
            return head->next;
        }
        pre->next=pre->next->next;
        return head;
    }
};