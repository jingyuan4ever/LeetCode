#include <stdlib.h>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *less(0), *more(0), *lp(0), *mp(0), *p=head;
        if(!head)
            return head;
        while(p){
            if(p->val<x){
                if(!lp){
                    less=p;
                    lp=p;
                }else{
                    lp->next=p;
                    lp=lp->next;
                }
            }else{
                if(!mp){
                    more=p;
                    mp=p;
                }else{
                    mp->next=p;
                    mp=mp->next;
                }
            }
            p=p->next;
        }
        if(mp!=nullptr)
            mp->next=nullptr;
        if(less!=nullptr){
            lp->next=more;
        }else{
            return more;
        }
        return less;
    }
};