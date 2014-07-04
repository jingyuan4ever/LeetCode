#include <stdlib.h>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(!l1){
            return l2;
        }
        if(!l2){
            return l1;
        }
        ListNode *p1=l1,*p2=l2,*p3(0),*ret(0);
        if(p1->val<p2->val){
            ret=p1;
            p3=p1;
            p1=p1->next;
            p3->next=nullptr;
        }else{
            ret=p2;
            p3=p2;
            p2=p2->next;
            p3->next=nullptr;
        }
        while(p1!=nullptr&&p2!=nullptr){
            if(p1->val<p2->val){
                p3->next=p1;
                p1=p1->next;
                p3=p3->next;
                p3->next=nullptr;
            }else{
                p3->next=p2;
                p2=p2->next;
                p3=p3->next;
                p3->next=nullptr;
            }
        }
        if(p1){
            p3->next=p1;
        }
        if(p2){
            p3->next=p2;
        }
        return ret;
    }
};