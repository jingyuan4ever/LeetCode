#include <stdlib.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if(l1==nullptr)
            return l2;
        if(l2==nullptr)
            return l1;
        ListNode *p1=l1, *p2=l2;
        int carry=0;
        p1->val+=p2->val+carry;
        carry=p1->val/10;
        p1->val%=10;
        while(p1->next&&p2->next){
            p1=p1->next;
            p2=p2->next;
            p1->val+=p2->val+carry;
            carry=p1->val/10;
            p1->val%=10;
        }
        if(p1->next==nullptr)
            p1->next=p2->next;
        while(p1->next){
            p1=p1->next;
            p1->val+=carry;
            carry=p1->val/10;
            p1->val%=10;
        }
        if(carry){
            p1->next=new ListNode(1);
        }
        return l1;
    }
};